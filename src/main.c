/*
 * Copyright © 2005 Novell, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software
 * and its documentation for any purpose is hereby granted without
 * fee, provided that the above copyright notice appear in all copies
 * and that both that copyright notice and this permission notice
 * appear in supporting documentation, and that the name of
 * Novell, Inc. not be used in advertising or publicity pertaining to
 * distribution of the software without specific, written prior permission.
 * Novell, Inc. makes no representations about the suitability of this
 * software for any purpose. It is provided "as is" without express or
 * implied warranty.
 *
 * NOVELL, INC. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN
 * NO EVENT SHALL NOVELL, INC. BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
 * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Author: David Reveman <davidr@novell.com>
 */

#ifdef HAVE_CONFIG_H
#  include "../config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#include <ecomp.h>

char *programName;
char **programArgv;
int programArgc;

char *backgroundImage = NULL;

REGION emptyRegion;
REGION infiniteRegion;
GLushort defaultColor[4] = { 0xffff, 0xffff, 0xffff, 0xffff };
Window currentRoot = 0;

int defaultRefreshRate = 50;
char *defaultTextureFilter = "Good";

Bool shutDown = FALSE;
Bool restartSignal = FALSE;

CompWindow *lastFoundWindow = 0;
CompWindow *lastDamagedWindow = 0;

Bool replaceCurrentWm = FALSE;
Bool indirectRendering = FALSE;
Bool strictBinding = TRUE;
Bool noDetection = FALSE;
Bool useDesktopHints = TRUE;
Bool onlyCurrentScreen = FALSE;

#ifdef USE_COW
Bool useCow = TRUE;
#endif

CompMetadata coreMetadata;

static void
usage(void)
{
   printf ("Usage: %s "
           "[--display DISPLAY] "
           "[--bg-image PNG] "
           "[--refresh-rate RATE]\n       "
           "[--fast-filter] "
           "[--indirect-rendering] "
           "[--loose-binding] "
           "[--no-detection]\n       "
           "[--ignore-desktop-hints] "
           "[--only-current-screen]"

#ifdef USE_COW
           " [--use-root-window]\n       "
#else
           "\n       "
#endif

           "[--version] "
           "[--help] "
           "[PLUGIN]...\n",
           programName);
}

void
compLogMessage(CompDisplay *d,
               char        *componentName,
               CompLogLevel level,
               char        *format,
               ...)
{
   va_list args;
   char message[2048];

   va_start (args, format);

   vsnprintf (message, 2048, format, args);

   if (d)
     (*d->logMessage)(d, componentName, level, message);
   else
     logMessage (d, componentName, level, message);

   va_end (args);
}

void
logMessage(CompDisplay *d,
           char        *componentName,
           CompLogLevel level,
           char        *message)
{
   char defaultMessage[2048];

   snprintf (defaultMessage, 2048, "%s (%s) - %s: %s",
             programName, componentName,
             logLevelToString (level), message);

   fprintf (stderr, "%s", defaultMessage);
   fprintf (stderr, "\n");
}

const char *
logLevelToString(CompLogLevel level)
{
   switch (level) {
      case CompLogLevelFatal:
        return "Fatal";

      case CompLogLevelError:
        return "Error";

      case CompLogLevelWarn:
        return "Warn";

      case CompLogLevelInfo:
        return "Info";

      case CompLogLevelDebug:
        return "Debug";

      default:
        break;
     }

   return "Unknown";
}

static void
signalHandler(int sig)
{
   int status;

   switch (sig) {
      case SIGCHLD:
        waitpid (-1, &status, WNOHANG | WUNTRACED);
        break;

      case SIGHUP:
        restartSignal = TRUE;
        break;

      case SIGINT:
      case SIGTERM:
        shutDown = TRUE;

      default:
        break;
     }
}

typedef struct _CompIOCtx
{
   int   offset;
   char *pluginData;
   char *textureFilterData;
   char *refreshRateData;
} CompIOCtx;

static int
readCoreXmlCallback(void *context,
                    char *buffer,
                    int   length)
{
   CompIOCtx *ctx = (CompIOCtx *)context;
   int offset = ctx->offset;
   int i, j;

   i = compReadXmlChunk ("<ecomp><core><display>", &offset, buffer, length);

   for (j = 0; j < COMP_DISPLAY_OPTION_NUM; j++)
     {
        CompMetadataOptionInfo info = coreDisplayOptionInfo[j];

        switch (j) {
           case COMP_DISPLAY_OPTION_ACTIVE_PLUGINS:
             if (ctx->pluginData)
               info.data = ctx->pluginData;
             break;

           case COMP_DISPLAY_OPTION_TEXTURE_FILTER:
             if (ctx->textureFilterData)
               info.data = ctx->textureFilterData;

           default:
             break;
          }

        i += compReadXmlChunkFromMetadataOptionInfo (&info,
                                                     &offset,
                                                     buffer + i,
                                                     length - i);
     }

   i += compReadXmlChunk ("</display><screen>", &offset,
                          buffer + i, length - 1);

   for (j = 0; j < COMP_SCREEN_OPTION_NUM; j++)
     {
        CompMetadataOptionInfo info = coreScreenOptionInfo[j];

        switch (j) {
           case COMP_SCREEN_OPTION_REFRESH_RATE:
             if (ctx->refreshRateData)
               info.data = ctx->refreshRateData;

           default:
             break;
          }

        i += compReadXmlChunkFromMetadataOptionInfo (&info,
                                                     &offset,
                                                     buffer + i,
                                                     length - i);
     }

   i += compReadXmlChunk ("</screen></core></ecomp>", &offset, buffer + i,
                          length - i);

   if (!offset && length > i)
     buffer[i++] = '\0';

   ctx->offset += i;

   return i;
}

int
main(int argc, char **argv)
{
   CompIOCtx ctx;
   char *displayName = 0;
   char *plugin[256];
   int i, nPlugin = 0;
   /* Bool      disableSm = FALSE; */
   char *refreshRateArg = NULL;

   programName = argv[0];
   programArgc = argc;
   programArgv = argv;

   compDisplays = NULL;

   signal (SIGHUP, signalHandler);
   signal (SIGCHLD, signalHandler);
   signal (SIGINT, signalHandler);
   signal (SIGTERM, signalHandler);

   emptyRegion.rects = &emptyRegion.extents;
   emptyRegion.numRects = 0;
   emptyRegion.extents.x1 = 0;
   emptyRegion.extents.y1 = 0;
   emptyRegion.extents.x2 = 0;
   emptyRegion.extents.y2 = 0;
   emptyRegion.size = 0;

   infiniteRegion.rects = &infiniteRegion.extents;
   infiniteRegion.numRects = 1;
   infiniteRegion.extents.x1 = MINSHORT;
   infiniteRegion.extents.y1 = MINSHORT;
   infiniteRegion.extents.x2 = MAXSHORT;
   infiniteRegion.extents.y2 = MAXSHORT;

   memset (&ctx, 0, sizeof (ctx));

   for (i = 1; i < argc; i++)
     {
        if (!strcmp (argv[i], "--help"))
          {
             usage ();
             return 0;
          }
        else if (!strcmp (argv[i], "--version"))
          {
             printf (PACKAGE_STRING "\n");
             return 0;
          }
        else if (!strcmp (argv[i], "--display"))
          {
             if (i + 1 < argc)
               displayName = argv[++i];
          }
        else if (!strcmp (argv[i], "--refresh-rate"))
          {
             if (i + 1 < argc)
               {
                  refreshRateArg = programArgv[++i];
                  defaultRefreshRate = atoi (refreshRateArg);
                  defaultRefreshRate = RESTRICT_VALUE (defaultRefreshRate,
                                                       1, 1000);
               }
          }
        else if (!strcmp (argv[i], "--fast-filter"))
          {
             ctx.textureFilterData = "<default>Fast</default>";
             defaultTextureFilter = "Fast";
          }
        else if (!strcmp (argv[i], "--indirect-rendering"))
          {
             indirectRendering = TRUE;
          }
        else if (!strcmp (argv[i], "--loose-binding"))
          {
             strictBinding = FALSE;
          }
        else if (!strcmp (argv[i], "--ignore-desktop-hints"))
          {
             useDesktopHints = FALSE;
          }
        else if (!strcmp (argv[i], "--only-current-screen"))
          {
             onlyCurrentScreen = TRUE;
          }

#ifdef USE_COW
        else if (!strcmp (argv[i], "--use-root-window"))
          {
             useCow = FALSE;
          }
#endif
        else if (!strcmp (argv[i], "--no-detection"))
          {
             noDetection = TRUE;
          }
        else if (!strcmp (argv[i], "--bg-image"))
          {
             if (i + 1 < argc)
               backgroundImage = argv[++i];
          }
        else if (*argv[i] == '-')
          {
             compLogMessage (NULL, "core", CompLogLevelWarn,
                             "Unknown option '%s'\n", argv[i]);
          }
        else
          {
             if (nPlugin < 256)
               plugin[nPlugin++] = argv[i];
          }
     }

   if (refreshRateArg)
     {
        ctx.refreshRateData = malloc (strlen (refreshRateArg) + 256);
        if (ctx.refreshRateData)
          sprintf (ctx.refreshRateData,
                   "<min>1</min><default>%s</default>",
                   refreshRateArg);
     }

   if (nPlugin)
     {
        int size = 256;

        for (i = 0; i < nPlugin; i++)
          size += strlen (plugin[i]) + 16;

        ctx.pluginData = malloc (size);
        if (ctx.pluginData)
          {
             char *ptr = ctx.pluginData;

             ptr += sprintf (ptr, "<type>string</type><default>");

             for (i = 0; i < nPlugin; i++)
               ptr += sprintf (ptr, "<value>%s</value>", plugin[i]);

             ptr += sprintf (ptr, "</default>");
          }
     }

   xmlInitParser ();

   LIBXML_TEST_VERSION;

   if (!compInitMetadata (&coreMetadata))
     {
        compLogMessage (NULL, "core", CompLogLevelFatal,
                        "Couldn't initialize core metadata");
        return 1;
     }

   if (!compAddMetadataFromIO (&coreMetadata,
                               readCoreXmlCallback, NULL,
                               &ctx))
     return 1;

   if (ctx.refreshRateData)
     free (ctx.refreshRateData);

   if (ctx.pluginData)
     free (ctx.pluginData);

   compAddMetadataFromFile (&coreMetadata, "core");

   if (!addDisplay (displayName))
     return 1;

   eventLoop ();

   xmlCleanupParser ();

   if (restartSignal)
     {
        execvp (programName, programArgv);
        return 1;
     }

   return 0;
}

