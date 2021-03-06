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

#define _WALL_OPTIONS_INTERNAL
#include "wall_options.h"

static int displayPrivateIndex;

static CompMetadata wallOptionsMetadata;

static CompPluginVTable *wallPluginVTable = NULL;
CompPluginVTable wallOptionsVTable;

#define GET_WALL_OPTIONS_DISPLAY(d) \
        ((WallOptionsDisplay *) (d)->privates[displayPrivateIndex].ptr)

#define WALL_OPTIONS_DISPLAY(d) \
        WallOptionsDisplay *od = GET_WALL_OPTIONS_DISPLAY (d)

#define GET_WALL_OPTIONS_SCREEN(s, od) \
        ((WallOptionsScreen *) (s)->privates[(od)->screenPrivateIndex].ptr)

#define WALL_OPTIONS_SCREEN(s) \
        WallOptionsScreen *os = GET_WALL_OPTIONS_SCREEN (s, GET_WALL_OPTIONS_DISPLAY (s->display))

typedef struct _WallOptionsDisplay
{
    int screenPrivateIndex;

    CompOption opt[WallDisplayOptionNum];
    wallDisplayOptionChangeNotifyProc notify[WallDisplayOptionNum];
} WallOptionsDisplay;

typedef struct _WallOptionsScreen
{
    CompOption opt[WallScreenOptionNum];
    wallScreenOptionChangeNotifyProc notify[WallScreenOptionNum];
} WallOptionsScreen;

Bool wallGetShowSwitcher (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionShowSwitcher].value.b;
}

CompOption * wallGetShowSwitcherOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionShowSwitcher];
}

void wallSetShowSwitcherNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionShowSwitcher] = notify;
}

Bool wallGetMiniscreen (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionMiniscreen].value.b;
}

CompOption * wallGetMiniscreenOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionMiniscreen];
}

void wallSetMiniscreenNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionMiniscreen] = notify;
}

float wallGetPreviewTimeout (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionPreviewTimeout].value.f;
}

CompOption * wallGetPreviewTimeoutOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionPreviewTimeout];
}

void wallSetPreviewTimeoutNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionPreviewTimeout] = notify;
}

int wallGetEdgeRadius (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionEdgeRadius].value.i;
}

CompOption * wallGetEdgeRadiusOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionEdgeRadius];
}

void wallSetEdgeRadiusNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionEdgeRadius] = notify;
}

unsigned short * wallGetOutlineColor (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionOutlineColor].value.c;
}

unsigned short wallGetOutlineColorRed (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionOutlineColor].value.c[0];
}

unsigned short wallGetOutlineColorGreen (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionOutlineColor].value.c[1];
}

unsigned short wallGetOutlineColorBlue (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionOutlineColor].value.c[2];
}

unsigned short wallGetOutlineColorAlpha (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionOutlineColor].value.c[3];
}

CompOption * wallGetOutlineColorOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionOutlineColor];
}

void wallSetOutlineColorNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionOutlineColor] = notify;
}

unsigned short * wallGetBackgroundGradientBaseColor (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientBaseColor].value.c;
}

unsigned short wallGetBackgroundGradientBaseColorRed (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientBaseColor].value.c[0];
}

unsigned short wallGetBackgroundGradientBaseColorGreen (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientBaseColor].value.c[1];
}

unsigned short wallGetBackgroundGradientBaseColorBlue (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientBaseColor].value.c[2];
}

unsigned short wallGetBackgroundGradientBaseColorAlpha (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientBaseColor].value.c[3];
}

CompOption * wallGetBackgroundGradientBaseColorOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionBackgroundGradientBaseColor];
}

void wallSetBackgroundGradientBaseColorNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionBackgroundGradientBaseColor] = notify;
}

unsigned short * wallGetBackgroundGradientHighlightColor (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientHighlightColor].value.c;
}

unsigned short wallGetBackgroundGradientHighlightColorRed (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientHighlightColor].value.c[0];
}

unsigned short wallGetBackgroundGradientHighlightColorGreen (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientHighlightColor].value.c[1];
}

unsigned short wallGetBackgroundGradientHighlightColorBlue (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientHighlightColor].value.c[2];
}

unsigned short wallGetBackgroundGradientHighlightColorAlpha (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientHighlightColor].value.c[3];
}

CompOption * wallGetBackgroundGradientHighlightColorOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionBackgroundGradientHighlightColor];
}

void wallSetBackgroundGradientHighlightColorNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionBackgroundGradientHighlightColor] = notify;
}

unsigned short * wallGetBackgroundGradientShadowColor (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientShadowColor].value.c;
}

unsigned short wallGetBackgroundGradientShadowColorRed (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientShadowColor].value.c[0];
}

unsigned short wallGetBackgroundGradientShadowColorGreen (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientShadowColor].value.c[1];
}

unsigned short wallGetBackgroundGradientShadowColorBlue (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientShadowColor].value.c[2];
}

unsigned short wallGetBackgroundGradientShadowColorAlpha (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionBackgroundGradientShadowColor].value.c[3];
}

CompOption * wallGetBackgroundGradientShadowColorOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionBackgroundGradientShadowColor];
}

void wallSetBackgroundGradientShadowColorNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionBackgroundGradientShadowColor] = notify;
}

unsigned short * wallGetThumbGradientBaseColor (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbGradientBaseColor].value.c;
}

unsigned short wallGetThumbGradientBaseColorRed (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbGradientBaseColor].value.c[0];
}

unsigned short wallGetThumbGradientBaseColorGreen (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbGradientBaseColor].value.c[1];
}

unsigned short wallGetThumbGradientBaseColorBlue (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbGradientBaseColor].value.c[2];
}

unsigned short wallGetThumbGradientBaseColorAlpha (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbGradientBaseColor].value.c[3];
}

CompOption * wallGetThumbGradientBaseColorOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionThumbGradientBaseColor];
}

void wallSetThumbGradientBaseColorNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionThumbGradientBaseColor] = notify;
}

unsigned short * wallGetThumbGradientHighlightColor (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbGradientHighlightColor].value.c;
}

unsigned short wallGetThumbGradientHighlightColorRed (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbGradientHighlightColor].value.c[0];
}

unsigned short wallGetThumbGradientHighlightColorGreen (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbGradientHighlightColor].value.c[1];
}

unsigned short wallGetThumbGradientHighlightColorBlue (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbGradientHighlightColor].value.c[2];
}

unsigned short wallGetThumbGradientHighlightColorAlpha (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbGradientHighlightColor].value.c[3];
}

CompOption * wallGetThumbGradientHighlightColorOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionThumbGradientHighlightColor];
}

void wallSetThumbGradientHighlightColorNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionThumbGradientHighlightColor] = notify;
}

unsigned short * wallGetThumbHighlightGradientBaseColor (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbHighlightGradientBaseColor].value.c;
}

unsigned short wallGetThumbHighlightGradientBaseColorRed (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbHighlightGradientBaseColor].value.c[0];
}

unsigned short wallGetThumbHighlightGradientBaseColorGreen (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbHighlightGradientBaseColor].value.c[1];
}

unsigned short wallGetThumbHighlightGradientBaseColorBlue (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbHighlightGradientBaseColor].value.c[2];
}

unsigned short wallGetThumbHighlightGradientBaseColorAlpha (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbHighlightGradientBaseColor].value.c[3];
}

CompOption * wallGetThumbHighlightGradientBaseColorOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionThumbHighlightGradientBaseColor];
}

void wallSetThumbHighlightGradientBaseColorNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionThumbHighlightGradientBaseColor] = notify;
}

unsigned short * wallGetThumbHighlightGradientShadowColor (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbHighlightGradientShadowColor].value.c;
}

unsigned short wallGetThumbHighlightGradientShadowColorRed (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbHighlightGradientShadowColor].value.c[0];
}

unsigned short wallGetThumbHighlightGradientShadowColorGreen (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbHighlightGradientShadowColor].value.c[1];
}

unsigned short wallGetThumbHighlightGradientShadowColorBlue (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbHighlightGradientShadowColor].value.c[2];
}

unsigned short wallGetThumbHighlightGradientShadowColorAlpha (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionThumbHighlightGradientShadowColor].value.c[3];
}

CompOption * wallGetThumbHighlightGradientShadowColorOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionThumbHighlightGradientShadowColor];
}

void wallSetThumbHighlightGradientShadowColorNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionThumbHighlightGradientShadowColor] = notify;
}

unsigned short * wallGetArrowBaseColor (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionArrowBaseColor].value.c;
}

unsigned short wallGetArrowBaseColorRed (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionArrowBaseColor].value.c[0];
}

unsigned short wallGetArrowBaseColorGreen (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionArrowBaseColor].value.c[1];
}

unsigned short wallGetArrowBaseColorBlue (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionArrowBaseColor].value.c[2];
}

unsigned short wallGetArrowBaseColorAlpha (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionArrowBaseColor].value.c[3];
}

CompOption * wallGetArrowBaseColorOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionArrowBaseColor];
}

void wallSetArrowBaseColorNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionArrowBaseColor] = notify;
}

unsigned short * wallGetArrowShadowColor (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionArrowShadowColor].value.c;
}

unsigned short wallGetArrowShadowColorRed (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionArrowShadowColor].value.c[0];
}

unsigned short wallGetArrowShadowColorGreen (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionArrowShadowColor].value.c[1];
}

unsigned short wallGetArrowShadowColorBlue (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionArrowShadowColor].value.c[2];
}

unsigned short wallGetArrowShadowColorAlpha (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionArrowShadowColor].value.c[3];
}

CompOption * wallGetArrowShadowColorOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionArrowShadowColor];
}

void wallSetArrowShadowColorNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionArrowShadowColor] = notify;
}

Bool wallGetMoveBackground (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionMoveBackground].value.b;
}

CompOption * wallGetMoveBackgroundOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionMoveBackground];
}

void wallSetMoveBackgroundNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionMoveBackground] = notify;
}

float wallGetSlideDuration (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return od->opt[WallDisplayOptionSlideDuration].value.f;
}

CompOption * wallGetSlideDurationOption (CompDisplay *d)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[WallDisplayOptionSlideDuration];
}

void wallSetSlideDurationNotify (CompDisplay *d, wallDisplayOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_DISPLAY(d);
    od->notify[WallDisplayOptionSlideDuration] = notify;
}

int wallGetMmmode (CompScreen *s)
{
    WALL_OPTIONS_SCREEN(s);
    return os->opt[WallScreenOptionMmmode].value.i;
}

CompOption * wallGetMmmodeOption (CompScreen *s)
{
    WALL_OPTIONS_SCREEN(s);
    return &os->opt[WallScreenOptionMmmode];
}

void wallSetMmmodeNotify (CompScreen *s, wallScreenOptionChangeNotifyProc notify)
{
    WALL_OPTIONS_SCREEN(s);
    os->notify[WallScreenOptionMmmode] = notify;
}

CompOption * wallGetDisplayOption (CompDisplay *d, WallDisplayOptions num)
{
    WALL_OPTIONS_DISPLAY(d);
    return &od->opt[num];
}

CompOption * wallGetScreenOption (CompScreen *s, WallScreenOptions num)
{
    WALL_OPTIONS_SCREEN(s);
    return &os->opt[num];
}

static const CompMetadataOptionInfo wallOptionsDisplayOptionInfo[] = {
    { "show_switcher", "bool", 0, 0, 0 },
    { "miniscreen", "bool", 0, 0, 0 },
    { "preview_timeout", "float", "<min>0.0</min><max>2.0</max>", 0, 0 },
    { "edge_radius", "int", "<min>0</min><max>20</max>", 0, 0 },
    { "outline_color", "color", 0, 0, 0 },
    { "background_gradient_base_color", "color", 0, 0, 0 },
    { "background_gradient_highlight_color", "color", 0, 0, 0 },
    { "background_gradient_shadow_color", "color", 0, 0, 0 },
    { "thumb_gradient_base_color", "color", 0, 0, 0 },
    { "thumb_gradient_highlight_color", "color", 0, 0, 0 },
    { "thumb_highlight_gradient_base_color", "color", 0, 0, 0 },
    { "thumb_highlight_gradient_shadow_color", "color", 0, 0, 0 },
    { "arrow_base_color", "color", 0, 0, 0 },
    { "arrow_shadow_color", "color", 0, 0, 0 },
    { "move_background", "bool", 0, 0, 0 },
    { "slide_duration", "float", "<min>0.05</min><max>5.0</max>", 0, 0 },
};

static Bool wallOptionsSetDisplayOption (CompPlugin *plugin, CompDisplay *d, char *name, CompOptionValue *value)
{
    WALL_OPTIONS_DISPLAY(d);
    CompOption *o;
    int        index;

    o = compFindOption (od->opt, WallDisplayOptionNum, name, &index);

    if (!o)
        return FALSE;

    switch (index)
    {
     case WallDisplayOptionShowSwitcher:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionShowSwitcher])
                (*od->notify[WallDisplayOptionShowSwitcher]) (d, o, WallDisplayOptionShowSwitcher);
            return TRUE;
        }
        break;
     case WallDisplayOptionMiniscreen:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionMiniscreen])
                (*od->notify[WallDisplayOptionMiniscreen]) (d, o, WallDisplayOptionMiniscreen);
            return TRUE;
        }
        break;
     case WallDisplayOptionPreviewTimeout:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionPreviewTimeout])
                (*od->notify[WallDisplayOptionPreviewTimeout]) (d, o, WallDisplayOptionPreviewTimeout);
            return TRUE;
        }
        break;
     case WallDisplayOptionEdgeRadius:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionEdgeRadius])
                (*od->notify[WallDisplayOptionEdgeRadius]) (d, o, WallDisplayOptionEdgeRadius);
            return TRUE;
        }
        break;
     case WallDisplayOptionOutlineColor:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionOutlineColor])
                (*od->notify[WallDisplayOptionOutlineColor]) (d, o, WallDisplayOptionOutlineColor);
            return TRUE;
        }
        break;
     case WallDisplayOptionBackgroundGradientBaseColor:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionBackgroundGradientBaseColor])
                (*od->notify[WallDisplayOptionBackgroundGradientBaseColor]) (d, o, WallDisplayOptionBackgroundGradientBaseColor);
            return TRUE;
        }
        break;
     case WallDisplayOptionBackgroundGradientHighlightColor:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionBackgroundGradientHighlightColor])
                (*od->notify[WallDisplayOptionBackgroundGradientHighlightColor]) (d, o, WallDisplayOptionBackgroundGradientHighlightColor);
            return TRUE;
        }
        break;
     case WallDisplayOptionBackgroundGradientShadowColor:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionBackgroundGradientShadowColor])
                (*od->notify[WallDisplayOptionBackgroundGradientShadowColor]) (d, o, WallDisplayOptionBackgroundGradientShadowColor);
            return TRUE;
        }
        break;
     case WallDisplayOptionThumbGradientBaseColor:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionThumbGradientBaseColor])
                (*od->notify[WallDisplayOptionThumbGradientBaseColor]) (d, o, WallDisplayOptionThumbGradientBaseColor);
            return TRUE;
        }
        break;
     case WallDisplayOptionThumbGradientHighlightColor:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionThumbGradientHighlightColor])
                (*od->notify[WallDisplayOptionThumbGradientHighlightColor]) (d, o, WallDisplayOptionThumbGradientHighlightColor);
            return TRUE;
        }
        break;
     case WallDisplayOptionThumbHighlightGradientBaseColor:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionThumbHighlightGradientBaseColor])
                (*od->notify[WallDisplayOptionThumbHighlightGradientBaseColor]) (d, o, WallDisplayOptionThumbHighlightGradientBaseColor);
            return TRUE;
        }
        break;
     case WallDisplayOptionThumbHighlightGradientShadowColor:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionThumbHighlightGradientShadowColor])
                (*od->notify[WallDisplayOptionThumbHighlightGradientShadowColor]) (d, o, WallDisplayOptionThumbHighlightGradientShadowColor);
            return TRUE;
        }
        break;
     case WallDisplayOptionArrowBaseColor:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionArrowBaseColor])
                (*od->notify[WallDisplayOptionArrowBaseColor]) (d, o, WallDisplayOptionArrowBaseColor);
            return TRUE;
        }
        break;
     case WallDisplayOptionArrowShadowColor:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionArrowShadowColor])
                (*od->notify[WallDisplayOptionArrowShadowColor]) (d, o, WallDisplayOptionArrowShadowColor);
            return TRUE;
        }
        break;
     case WallDisplayOptionMoveBackground:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionMoveBackground])
                (*od->notify[WallDisplayOptionMoveBackground]) (d, o, WallDisplayOptionMoveBackground);
            return TRUE;
        }
        break;
     case WallDisplayOptionSlideDuration:
        if (compSetDisplayOption (d, o, value))
        {
            if (od->notify[WallDisplayOptionSlideDuration])
                (*od->notify[WallDisplayOptionSlideDuration]) (d, o, WallDisplayOptionSlideDuration);
            return TRUE;
        }
        break;
    default:
        break;
    }
    return FALSE;
}

static CompOption * wallOptionsGetDisplayOptions (CompPlugin *plugin, CompDisplay *d, int *count)
{
    WALL_OPTIONS_DISPLAY(d);
    *count = WallDisplayOptionNum;
    return od->opt;
}

static const CompMetadataOptionInfo wallOptionsScreenOptionInfo[] = {
    { "mmmode", "int", "<min>0</min><max>1</max>", 0, 0 },
};

static Bool wallOptionsSetScreenOption (CompPlugin *plugin, CompScreen *s, char *name, CompOptionValue *value)
{
    WALL_OPTIONS_SCREEN(s);
    CompOption *o;
    int        index;

    o = compFindOption (os->opt, WallScreenOptionNum, name, &index);

    if (!o)
        return FALSE;

    switch (index)
    {
     case WallScreenOptionMmmode:
        if (compSetScreenOption (s, o, value))
        {
            if (os->notify[WallScreenOptionMmmode])
                (*os->notify[WallScreenOptionMmmode]) (s, o, WallScreenOptionMmmode);
            return TRUE;
        }
        break;
    default:
        break;
    }
    return FALSE;
}

static CompOption * wallOptionsGetScreenOptions (CompPlugin *plugin, CompScreen *s, int *count)
{
    WALL_OPTIONS_SCREEN(s);
    *count = WallScreenOptionNum;
    return os->opt;
}

static Bool wallOptionsInitScreen (CompPlugin *p, CompScreen *s)
{
    WallOptionsScreen *os;
    
    WALL_OPTIONS_DISPLAY (s->display);

    os = calloc (1, sizeof(WallOptionsScreen));
    if (!os)
        return FALSE;

    s->privates[od->screenPrivateIndex].ptr = os;

    if (!compInitScreenOptionsFromMetadata (s, &wallOptionsMetadata, wallOptionsScreenOptionInfo, os->opt, WallScreenOptionNum))
    {
        free (os);
        return FALSE;
    }
    if (wallPluginVTable && wallPluginVTable->initScreen)
        return wallPluginVTable->initScreen (p, s);
    return TRUE;
}

static void wallOptionsFiniScreen (CompPlugin *p, CompScreen *s)
{
    if (wallPluginVTable && wallPluginVTable->finiScreen)
        return wallPluginVTable->finiScreen (p, s);

    WALL_OPTIONS_SCREEN (s);


    compFiniScreenOptions (s, os->opt, WallScreenOptionNum);

    free (os);
}

static Bool wallOptionsInitDisplay (CompPlugin *p, CompDisplay *d)
{
    WallOptionsDisplay *od;
   
    
    od = calloc (1, sizeof(WallOptionsDisplay));
    if (!od)
        return FALSE;

    od->screenPrivateIndex = allocateScreenPrivateIndex(d);
    if (od->screenPrivateIndex < 0)
    {
        free(od);
        return FALSE;
    }

    d->privates[displayPrivateIndex].ptr = od;

    if (!compInitDisplayOptionsFromMetadata (d, &wallOptionsMetadata, wallOptionsDisplayOptionInfo, od->opt, WallDisplayOptionNum))
    {
        free (od);
        return FALSE;
    }
    if (wallPluginVTable && wallPluginVTable->initDisplay)
        return wallPluginVTable->initDisplay (p, d);
    return TRUE;
}

static void wallOptionsFiniDisplay (CompPlugin *p, CompDisplay *d)
{
    if (wallPluginVTable && wallPluginVTable->finiDisplay)
        return wallPluginVTable->finiDisplay (p, d);

    WALL_OPTIONS_DISPLAY (d);

    freeScreenPrivateIndex(d, od->screenPrivateIndex);

    compFiniDisplayOptions (d, od->opt, WallDisplayOptionNum);

    free (od);
}

static Bool wallOptionsInit (CompPlugin *p)
{
    displayPrivateIndex = allocateDisplayPrivateIndex();
    if (displayPrivateIndex < 0)
        return FALSE;

    if (!compInitPluginMetadataFromInfo (&wallOptionsMetadata, "wall",wallOptionsDisplayOptionInfo, WallDisplayOptionNum, wallOptionsScreenOptionInfo, WallScreenOptionNum))
        return FALSE;

    compAddMetadataFromFile (&wallOptionsMetadata, "wall");
    if (wallPluginVTable && wallPluginVTable->init)
        return wallPluginVTable->init (p);
    return TRUE;
}

static void wallOptionsFini (CompPlugin *p)
{
    if (wallPluginVTable && wallPluginVTable->fini)
        return wallPluginVTable->fini (p);

    if (displayPrivateIndex >= 0)
        freeDisplayPrivateIndex(displayPrivateIndex);

    compFiniMetadata (&wallOptionsMetadata);
}

static CompMetadata *
wallOptionsGetMetadata (CompPlugin *plugin)
{
    return &wallOptionsMetadata;
}

CompPluginVTable *getCompPluginInfo (void)
{
    if (!wallPluginVTable)
    {
        wallPluginVTable = wallOptionsGetCompPluginInfo ();
        memcpy(&wallOptionsVTable, wallPluginVTable, sizeof(CompPluginVTable));
        wallOptionsVTable.getMetadata = wallOptionsGetMetadata;
        wallOptionsVTable.init = wallOptionsInit;
        wallOptionsVTable.fini = wallOptionsFini;
        wallOptionsVTable.initDisplay = wallOptionsInitDisplay;
        wallOptionsVTable.finiDisplay = wallOptionsFiniDisplay;
        wallOptionsVTable.initScreen = wallOptionsInitScreen;
        wallOptionsVTable.finiScreen = wallOptionsFiniScreen;
        wallOptionsVTable.getDisplayOptions = wallOptionsGetDisplayOptions;
	wallOptionsVTable.setDisplayOption = wallOptionsSetDisplayOption;
	wallOptionsVTable.getScreenOptions = wallOptionsGetScreenOptions;
	wallOptionsVTable.setScreenOption = wallOptionsSetScreenOption;
	
    }
    return &wallOptionsVTable;
}

