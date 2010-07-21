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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ecomp.h>

#define _RING_OPTIONS_INTERNAL
#include "ring_options.h"

static int displayPrivateIndex;

static CompMetadata ringOptionsMetadata;

static CompPluginVTable *ringPluginVTable = NULL;
CompPluginVTable ringOptionsVTable;

#define GET_RING_OPTIONS_DISPLAY(d) \
        ((RingOptionsDisplay *) (d)->privates[displayPrivateIndex].ptr)

#define RING_OPTIONS_DISPLAY(d) \
        RingOptionsDisplay *od = GET_RING_OPTIONS_DISPLAY (d)

#define GET_RING_OPTIONS_SCREEN(s, od) \
        ((RingOptionsScreen *) (s)->privates[(od)->screenPrivateIndex].ptr)

#define RING_OPTIONS_SCREEN(s) \
        RingOptionsScreen *os = GET_RING_OPTIONS_SCREEN (s, GET_RING_OPTIONS_DISPLAY (s->display))

typedef struct _RingOptionsDisplay
{
    int screenPrivateIndex;

} RingOptionsDisplay;

typedef struct _RingOptionsScreen
{
    CompOption opt[RingScreenOptionNum];
    ringScreenOptionChangeNotifyProc notify[RingScreenOptionNum];
} RingOptionsScreen;

float ringGetSpeed (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionSpeed].value.f;
}

CompOption * ringGetSpeedOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionSpeed];
}

void ringSetSpeedNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionSpeed] = notify;
}

float ringGetTimestep (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTimestep].value.f;
}

CompOption * ringGetTimestepOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionTimestep];
}

void ringSetTimestepNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionTimestep] = notify;
}

int ringGetInactiveOpacity (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionInactiveOpacity].value.i;
}

CompOption * ringGetInactiveOpacityOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionInactiveOpacity];
}

void ringSetInactiveOpacityNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionInactiveOpacity] = notify;
}

CompMatch * ringGetWindowMatch (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionWindowMatch].value.match;
}

CompOption * ringGetWindowMatchOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionWindowMatch];
}

void ringSetWindowMatchNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionWindowMatch] = notify;
}

int ringGetOverlayIcon (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionOverlayIcon].value.i;
}

CompOption * ringGetOverlayIconOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionOverlayIcon];
}

void ringSetOverlayIconNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionOverlayIcon] = notify;
}

Bool ringGetDarkenBack (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionDarkenBack].value.b;
}

CompOption * ringGetDarkenBackOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionDarkenBack];
}

void ringSetDarkenBackNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionDarkenBack] = notify;
}

Bool ringGetMinimized (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionMinimized].value.b;
}

CompOption * ringGetMinimizedOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionMinimized];
}

void ringSetMinimizedNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionMinimized] = notify;
}

Bool ringGetSelectWithMouse (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionSelectWithMouse].value.b;
}

CompOption * ringGetSelectWithMouseOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionSelectWithMouse];
}

void ringSetSelectWithMouseNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionSelectWithMouse] = notify;
}

Bool ringGetRingClockwise (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionRingClockwise].value.b;
}

CompOption * ringGetRingClockwiseOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionRingClockwise];
}

void ringSetRingClockwiseNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionRingClockwise] = notify;
}

int ringGetRingWidth (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionRingWidth].value.i;
}

CompOption * ringGetRingWidthOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionRingWidth];
}

void ringSetRingWidthNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionRingWidth] = notify;
}

int ringGetRingHeight (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionRingHeight].value.i;
}

CompOption * ringGetRingHeightOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionRingHeight];
}

void ringSetRingHeightNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionRingHeight] = notify;
}

int ringGetThumbWidth (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionThumbWidth].value.i;
}

CompOption * ringGetThumbWidthOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionThumbWidth];
}

void ringSetThumbWidthNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionThumbWidth] = notify;
}

int ringGetThumbHeight (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionThumbHeight].value.i;
}

CompOption * ringGetThumbHeightOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionThumbHeight];
}

void ringSetThumbHeightNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionThumbHeight] = notify;
}

float ringGetMinBrightness (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionMinBrightness].value.f;
}

CompOption * ringGetMinBrightnessOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionMinBrightness];
}

void ringSetMinBrightnessNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionMinBrightness] = notify;
}

float ringGetMinScale (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionMinScale].value.f;
}

CompOption * ringGetMinScaleOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionMinScale];
}

void ringSetMinScaleNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionMinScale] = notify;
}

Bool ringGetWindowTitle (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionWindowTitle].value.b;
}

CompOption * ringGetWindowTitleOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionWindowTitle];
}

void ringSetWindowTitleNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionWindowTitle] = notify;
}

Bool ringGetTitleFontBold (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTitleFontBold].value.b;
}

CompOption * ringGetTitleFontBoldOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionTitleFontBold];
}

void ringSetTitleFontBoldNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionTitleFontBold] = notify;
}

int ringGetTitleFontSize (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTitleFontSize].value.i;
}

CompOption * ringGetTitleFontSizeOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionTitleFontSize];
}

void ringSetTitleFontSizeNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionTitleFontSize] = notify;
}

unsigned short * ringGetTitleBackColor (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTitleBackColor].value.c;
}

unsigned short ringGetTitleBackColorRed (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTitleBackColor].value.c[0];
}

unsigned short ringGetTitleBackColorGreen (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTitleBackColor].value.c[1];
}

unsigned short ringGetTitleBackColorBlue (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTitleBackColor].value.c[2];
}

unsigned short ringGetTitleBackColorAlpha (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTitleBackColor].value.c[3];
}

CompOption * ringGetTitleBackColorOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionTitleBackColor];
}

void ringSetTitleBackColorNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionTitleBackColor] = notify;
}

unsigned short * ringGetTitleFontColor (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTitleFontColor].value.c;
}

unsigned short ringGetTitleFontColorRed (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTitleFontColor].value.c[0];
}

unsigned short ringGetTitleFontColorGreen (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTitleFontColor].value.c[1];
}

unsigned short ringGetTitleFontColorBlue (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTitleFontColor].value.c[2];
}

unsigned short ringGetTitleFontColorAlpha (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTitleFontColor].value.c[3];
}

CompOption * ringGetTitleFontColorOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionTitleFontColor];
}

void ringSetTitleFontColorNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionTitleFontColor] = notify;
}

int ringGetTitleTextPlacement (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return os->opt[RingScreenOptionTitleTextPlacement].value.i;
}

CompOption * ringGetTitleTextPlacementOption (CompScreen *s)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[RingScreenOptionTitleTextPlacement];
}

void ringSetTitleTextPlacementNotify (CompScreen *s, ringScreenOptionChangeNotifyProc notify)
{
    RING_OPTIONS_SCREEN(s);
    os->notify[RingScreenOptionTitleTextPlacement] = notify;
}

CompOption * ringGetScreenOption (CompScreen *s, RingScreenOptions num)
{
    RING_OPTIONS_SCREEN(s);
    return &os->opt[num];
}

static const CompMetadataOptionInfo ringOptionsScreenOptionInfo[] = {
    { "speed", "float", "<min>0.1</min><max>50.0</max>", 0, 0 },
    { "timestep", "float", "<min>0.1</min><max>50.0</max>", 0, 0 },
    { "inactive_opacity", "int", "<min>1</min><max>100</max>", 0, 0 },
    { "window_match", "match", 0, 0, 0 },
    { "overlay_icon", "int", "<min>0</min><max>2</max>", 0, 0 },
    { "darken_back", "bool", 0, 0, 0 },
    { "minimized", "bool", 0, 0, 0 },
    { "select_with_mouse", "bool", 0, 0, 0 },
    { "ring_clockwise", "bool", 0, 0, 0 },
    { "ring_width", "int", "<min>1</min><max>100</max>", 0, 0 },
    { "ring_height", "int", "<min>1</min><max>100</max>", 0, 0 },
    { "thumb_width", "int", "<min>10</min><max>1024</max>", 0, 0 },
    { "thumb_height", "int", "<min>10</min><max>1024</max>", 0, 0 },
    { "min_brightness", "float", "<min>0.1</min><max>1.0</max>", 0, 0 },
    { "min_scale", "float", "<min>0.1</min><max>1.0</max>", 0, 0 },
    { "window_title", "bool", 0, 0, 0 },
    { "title_font_bold", "bool", 0, 0, 0 },
    { "title_font_size", "int", "<min>6</min><max>96</max>", 0, 0 },
    { "title_back_color", "color", 0, 0, 0 },
    { "title_font_color", "color", 0, 0, 0 },
    { "title_text_placement", "int", "<min>0</min><max>2</max>", 0, 0 },
};

static Bool ringOptionsSetScreenOption (CompPlugin *plugin, CompScreen *s, char *name, CompOptionValue *value)
{
    RING_OPTIONS_SCREEN(s);
    CompOption *o;
    int        index;

    o = compFindOption (os->opt, RingScreenOptionNum, name, &index);

    if (!o)
        return FALSE;

    switch (index)
    {
     case RingScreenOptionSpeed:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionSpeed])
                (*os->notify[RingScreenOptionSpeed]) (s, o, RingScreenOptionSpeed);
            return TRUE;
        }
        break;
     case RingScreenOptionTimestep:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionTimestep])
                (*os->notify[RingScreenOptionTimestep]) (s, o, RingScreenOptionTimestep);
            return TRUE;
        }
        break;
     case RingScreenOptionInactiveOpacity:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionInactiveOpacity])
                (*os->notify[RingScreenOptionInactiveOpacity]) (s, o, RingScreenOptionInactiveOpacity);
            return TRUE;
        }
        break;
     case RingScreenOptionWindowMatch:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionWindowMatch])
                (*os->notify[RingScreenOptionWindowMatch]) (s, o, RingScreenOptionWindowMatch);
            return TRUE;
        }
        break;
     case RingScreenOptionOverlayIcon:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionOverlayIcon])
                (*os->notify[RingScreenOptionOverlayIcon]) (s, o, RingScreenOptionOverlayIcon);
            return TRUE;
        }
        break;
     case RingScreenOptionDarkenBack:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionDarkenBack])
                (*os->notify[RingScreenOptionDarkenBack]) (s, o, RingScreenOptionDarkenBack);
            return TRUE;
        }
        break;
     case RingScreenOptionMinimized:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionMinimized])
                (*os->notify[RingScreenOptionMinimized]) (s, o, RingScreenOptionMinimized);
            return TRUE;
        }
        break;
     case RingScreenOptionSelectWithMouse:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionSelectWithMouse])
                (*os->notify[RingScreenOptionSelectWithMouse]) (s, o, RingScreenOptionSelectWithMouse);
            return TRUE;
        }
        break;
     case RingScreenOptionRingClockwise:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionRingClockwise])
                (*os->notify[RingScreenOptionRingClockwise]) (s, o, RingScreenOptionRingClockwise);
            return TRUE;
        }
        break;
     case RingScreenOptionRingWidth:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionRingWidth])
                (*os->notify[RingScreenOptionRingWidth]) (s, o, RingScreenOptionRingWidth);
            return TRUE;
        }
        break;
     case RingScreenOptionRingHeight:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionRingHeight])
                (*os->notify[RingScreenOptionRingHeight]) (s, o, RingScreenOptionRingHeight);
            return TRUE;
        }
        break;
     case RingScreenOptionThumbWidth:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionThumbWidth])
                (*os->notify[RingScreenOptionThumbWidth]) (s, o, RingScreenOptionThumbWidth);
            return TRUE;
        }
        break;
     case RingScreenOptionThumbHeight:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionThumbHeight])
                (*os->notify[RingScreenOptionThumbHeight]) (s, o, RingScreenOptionThumbHeight);
            return TRUE;
        }
        break;
     case RingScreenOptionMinBrightness:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionMinBrightness])
                (*os->notify[RingScreenOptionMinBrightness]) (s, o, RingScreenOptionMinBrightness);
            return TRUE;
        }
        break;
     case RingScreenOptionMinScale:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionMinScale])
                (*os->notify[RingScreenOptionMinScale]) (s, o, RingScreenOptionMinScale);
            return TRUE;
        }
        break;
     case RingScreenOptionWindowTitle:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionWindowTitle])
                (*os->notify[RingScreenOptionWindowTitle]) (s, o, RingScreenOptionWindowTitle);
            return TRUE;
        }
        break;
     case RingScreenOptionTitleFontBold:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionTitleFontBold])
                (*os->notify[RingScreenOptionTitleFontBold]) (s, o, RingScreenOptionTitleFontBold);
            return TRUE;
        }
        break;
     case RingScreenOptionTitleFontSize:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionTitleFontSize])
                (*os->notify[RingScreenOptionTitleFontSize]) (s, o, RingScreenOptionTitleFontSize);
            return TRUE;
        }
        break;
     case RingScreenOptionTitleBackColor:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionTitleBackColor])
                (*os->notify[RingScreenOptionTitleBackColor]) (s, o, RingScreenOptionTitleBackColor);
            return TRUE;
        }
        break;
     case RingScreenOptionTitleFontColor:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionTitleFontColor])
                (*os->notify[RingScreenOptionTitleFontColor]) (s, o, RingScreenOptionTitleFontColor);
            return TRUE;
        }
        break;
     case RingScreenOptionTitleTextPlacement:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[RingScreenOptionTitleTextPlacement])
                (*os->notify[RingScreenOptionTitleTextPlacement]) (s, o, RingScreenOptionTitleTextPlacement);
            return TRUE;
        }
        break;
    default:
        break;
    }
    return FALSE;
}

static CompOption * ringOptionsGetScreenOptions (CompPlugin *plugin, CompScreen *s, int *count)
{
    RING_OPTIONS_SCREEN(s);
    *count = RingScreenOptionNum;
    return os->opt;
}

static Bool ringOptionsInitScreen (CompPlugin *p, CompScreen *s)
{
    RingOptionsScreen *os;
    
    RING_OPTIONS_DISPLAY (s->display);

    os = calloc (1, sizeof(RingOptionsScreen));
    if (!os)
        return FALSE;

    s->privates[od->screenPrivateIndex].ptr = os;

    if (!compInitScreenOptionsFromMetadata (s, &ringOptionsMetadata, ringOptionsScreenOptionInfo, os->opt, RingScreenOptionNum))
    {
        free (os);
        return FALSE;
    }
    if (ringPluginVTable && ringPluginVTable->initScreen)
        return ringPluginVTable->initScreen (p, s);
    return TRUE;
}

static void ringOptionsFiniScreen (CompPlugin *p, CompScreen *s)
{
    if (ringPluginVTable && ringPluginVTable->finiScreen)
        return ringPluginVTable->finiScreen (p, s);

    RING_OPTIONS_SCREEN (s);


    compFiniScreenOptions (s, os->opt, RingScreenOptionNum);

    free (os);
}

static Bool ringOptionsInitDisplay (CompPlugin *p, CompDisplay *d)
{
    RingOptionsDisplay *od;
   
    
    od = calloc (1, sizeof(RingOptionsDisplay));
    if (!od)
        return FALSE;

    od->screenPrivateIndex = allocateScreenPrivateIndex(d);
    if (od->screenPrivateIndex < 0)
    {
        free(od);
        return FALSE;
    }

    d->privates[displayPrivateIndex].ptr = od;

        if (ringPluginVTable && ringPluginVTable->initDisplay)
        return ringPluginVTable->initDisplay (p, d);
    return TRUE;
}

static void ringOptionsFiniDisplay (CompPlugin *p, CompDisplay *d)
{
    if (ringPluginVTable && ringPluginVTable->finiDisplay)
        return ringPluginVTable->finiDisplay (p, d);

    RING_OPTIONS_DISPLAY (d);

    freeScreenPrivateIndex(d, od->screenPrivateIndex);
    free (od);
}

static Bool ringOptionsInit (CompPlugin *p)
{
    displayPrivateIndex = allocateDisplayPrivateIndex();
    if (displayPrivateIndex < 0)
        return FALSE;

    if (!compInitPluginMetadataFromInfo (&ringOptionsMetadata, "ring",0, 0, ringOptionsScreenOptionInfo, RingScreenOptionNum))
        return FALSE;

    compAddMetadataFromFile (&ringOptionsMetadata, "ring");
    if (ringPluginVTable && ringPluginVTable->init)
        return ringPluginVTable->init (p);
    return TRUE;
}

static void ringOptionsFini (CompPlugin *p)
{
    if (ringPluginVTable && ringPluginVTable->fini)
        return ringPluginVTable->fini (p);

    if (displayPrivateIndex >= 0)
        freeDisplayPrivateIndex(displayPrivateIndex);

    compFiniMetadata (&ringOptionsMetadata);
}

static CompMetadata *
ringOptionsGetMetadata (CompPlugin *plugin)
{
    return &ringOptionsMetadata;
}

CompPluginVTable *getCompPluginInfo (void)
{
    if (!ringPluginVTable)
    {
        ringPluginVTable = ringOptionsGetCompPluginInfo ();
        memcpy(&ringOptionsVTable, ringPluginVTable, sizeof(CompPluginVTable));
        ringOptionsVTable.getMetadata = ringOptionsGetMetadata;
        ringOptionsVTable.init = ringOptionsInit;
        ringOptionsVTable.fini = ringOptionsFini;
        ringOptionsVTable.initDisplay = ringOptionsInitDisplay;
        ringOptionsVTable.finiDisplay = ringOptionsFiniDisplay;
        ringOptionsVTable.initScreen = ringOptionsInitScreen;
        ringOptionsVTable.finiScreen = ringOptionsFiniScreen;
        ringOptionsVTable.getScreenOptions = ringOptionsGetScreenOptions;
	ringOptionsVTable.setScreenOption = ringOptionsSetScreenOption;
	
    }
    return &ringOptionsVTable;
}
