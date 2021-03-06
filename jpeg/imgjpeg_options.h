/*
 * This file is autogenerated with bcop:
 * The Ecomp option code generator
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _IMGJPEG_OPTIONS_H
#define _IMGJPEG_OPTIONS_H

#ifndef _IMGJPEG_OPTIONS_INTERNAL
#define getCompPluginInfo imgjpegOptionsGetCompPluginInfo
#endif

#ifdef  __cplusplus
extern "C" {
#endif

CompPluginVTable *imgjpegOptionsGetCompPluginInfo (void);

typedef enum
{
    ImgjpegDisplayOptionQuality,
    ImgjpegDisplayOptionNum
} ImgjpegDisplayOptions;

typedef void (*imgjpegDisplayOptionChangeNotifyProc) (CompDisplay *display, CompOption *opt, ImgjpegDisplayOptions num);

CompOption *imgjpegGetDisplayOption (CompDisplay *d, ImgjpegDisplayOptions num);

typedef enum
{
    ImgjpegScreenOptionNum
} ImgjpegScreenOptions;

typedef void (*imgjpegScreenOptionChangeNotifyProc) (CompScreen *screen, CompOption *opt, ImgjpegScreenOptions num);

CompOption *imgjpegGetScreenOption (CompScreen *s, ImgjpegScreenOptions num);

int              imgjpegGetQuality (CompDisplay *d);
CompOption *     imgjpegGetQualityOption (CompDisplay *d);
void             imgjpegSetQualityNotify (CompDisplay *d, imgjpegDisplayOptionChangeNotifyProc notify);
            
#ifdef  __cplusplus
}
#endif

#endif
