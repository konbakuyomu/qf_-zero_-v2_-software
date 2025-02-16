/*******************************************************************************
 * Size: 18 px
 * Bpp: 4
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef WATCH_04_FONT_18
#define WATCH_04_FONT_18 1
#endif

#if WATCH_04_FONT_18

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002E "." */
    0x12, 0xe, 0xf3, 0xbe, 0x20,

    /* U+002F "/" */
    0x0, 0x0, 0x85, 0x0, 0x3, 0xf9, 0x0, 0x7,
    0xf5, 0x0, 0xa, 0xf1, 0x0, 0xe, 0xe0, 0x0,
    0x2f, 0xa0, 0x0, 0x5f, 0x70, 0x0, 0x9f, 0x30,
    0x0, 0xcf, 0x0, 0x0, 0xfc, 0x0, 0x4, 0xf8,
    0x0, 0x7, 0xf5, 0x0, 0xb, 0xf1, 0x0, 0xe,
    0xe0, 0x0, 0x2f, 0xa0, 0x0, 0x6f, 0x60, 0x0,
    0x9f, 0x30, 0x0,

    /* U+0030 "0" */
    0x0, 0x8d, 0xfe, 0xa2, 0x0, 0xc, 0xfc, 0x9b,
    0xfe, 0x20, 0x6f, 0xb0, 0x0, 0x6f, 0xa0, 0xbf,
    0x40, 0x0, 0xf, 0xf0, 0xdf, 0x10, 0x0, 0xd,
    0xf1, 0xef, 0x0, 0x0, 0xc, 0xf2, 0xef, 0x0,
    0x0, 0xc, 0xf2, 0xef, 0x0, 0x0, 0xc, 0xf2,
    0xdf, 0x10, 0x0, 0xd, 0xf1, 0xbf, 0x40, 0x0,
    0xf, 0xf0, 0x6f, 0xb0, 0x0, 0x7f, 0xa0, 0xc,
    0xfc, 0x9b, 0xfe, 0x20, 0x0, 0x8d, 0xfe, 0xa2,
    0x0,

    /* U+0031 "1" */
    0x0, 0x19, 0xf9, 0x8, 0xff, 0xf9, 0x4f, 0xd8,
    0xf9, 0x25, 0x4, 0xf9, 0x0, 0x4, 0xf9, 0x0,
    0x4, 0xf9, 0x0, 0x4, 0xf9, 0x0, 0x4, 0xf9,
    0x0, 0x4, 0xf9, 0x0, 0x4, 0xf9, 0x0, 0x4,
    0xf9, 0x0, 0x4, 0xf9, 0x0, 0x4, 0xf9,

    /* U+0032 "2" */
    0x0, 0x4b, 0xef, 0xc4, 0x0, 0x6, 0xfe, 0x99,
    0xff, 0x50, 0x1f, 0xd1, 0x0, 0x3f, 0xe0, 0x18,
    0x40, 0x0, 0xe, 0xf1, 0x0, 0x0, 0x0, 0xf,
    0xf0, 0x0, 0x0, 0x0, 0x6f, 0xa0, 0x0, 0x0,
    0x3, 0xfe, 0x10, 0x0, 0x0, 0x3f, 0xf3, 0x0,
    0x0, 0x3, 0xff, 0x40, 0x0, 0x0, 0x3f, 0xf4,
    0x0, 0x0, 0x3, 0xff, 0x40, 0x0, 0x0, 0x2f,
    0xfb, 0x77, 0x77, 0x71, 0x5f, 0xff, 0xff, 0xff,
    0xf2,

    /* U+0033 "3" */
    0xe, 0xff, 0xff, 0xff, 0x80, 0x6, 0x77, 0x78,
    0xff, 0x40, 0x0, 0x0, 0x1d, 0xf4, 0x0, 0x0,
    0x1, 0xdf, 0x30, 0x0, 0x0, 0x1d, 0xf4, 0x0,
    0x0, 0x1, 0xdf, 0xff, 0xd6, 0x0, 0x1, 0xd8,
    0x46, 0xef, 0x70, 0x0, 0x0, 0x0, 0x2f, 0xe0,
    0x0, 0x0, 0x0, 0xc, 0xf2, 0x2, 0x0, 0x0,
    0xd, 0xf2, 0x6f, 0x50, 0x0, 0x4f, 0xd0, 0x1d,
    0xfb, 0x8a, 0xff, 0x30, 0x1, 0x8d, 0xfe, 0xa2,
    0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x7f, 0x60, 0x0, 0x0, 0x0,
    0x3f, 0xf6, 0x0, 0x0, 0x0, 0xd, 0xff, 0x60,
    0x0, 0x0, 0xa, 0xfa, 0xf6, 0x0, 0x0, 0x6,
    0xf8, 0x6f, 0x60, 0x0, 0x2, 0xfc, 0x6, 0xf6,
    0x0, 0x0, 0xce, 0x10, 0x6f, 0x60, 0x0, 0x8f,
    0x40, 0x6, 0xf6, 0x0, 0x4f, 0xd8, 0x88, 0xbf,
    0xb8, 0x17, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0,
    0x0, 0x0, 0x6f, 0x60, 0x0, 0x0, 0x0, 0x6,
    0xf6, 0x0, 0x0, 0x0, 0x0, 0x6f, 0x60, 0x0,

    /* U+0035 "5" */
    0xd, 0xff, 0xff, 0xff, 0x10, 0xfe, 0x77, 0x77,
    0x70, 0x1f, 0xa0, 0x0, 0x0, 0x3, 0xf8, 0x0,
    0x0, 0x0, 0x5f, 0x65, 0x76, 0x10, 0x7, 0xff,
    0xff, 0xff, 0x50, 0x8f, 0x91, 0x5, 0xff, 0x20,
    0x10, 0x0, 0x7, 0xf8, 0x0, 0x0, 0x0, 0x4f,
    0xa0, 0x20, 0x0, 0x4, 0xfa, 0xbe, 0x20, 0x0,
    0xbf, 0x54, 0xff, 0xa9, 0xdf, 0xb0, 0x3, 0xbe,
    0xfd, 0x70, 0x0,

    /* U+0036 "6" */
    0x0, 0x0, 0xb, 0xf6, 0x0, 0x0, 0x0, 0x7f,
    0x90, 0x0, 0x0, 0x3, 0xfc, 0x0, 0x0, 0x0,
    0x1e, 0xd1, 0x0, 0x0, 0x0, 0xaf, 0x77, 0x72,
    0x0, 0x4, 0xff, 0xff, 0xff, 0x90, 0xb, 0xfc,
    0x20, 0x3d, 0xf6, 0xf, 0xf1, 0x0, 0x2, 0xfd,
    0x1f, 0xc0, 0x0, 0x0, 0xff, 0xf, 0xe0, 0x0,
    0x0, 0xfe, 0xb, 0xf5, 0x0, 0x8, 0xf9, 0x2,
    0xff, 0xb9, 0xcf, 0xe1, 0x0, 0x2a, 0xef, 0xe9,
    0x10,

    /* U+0037 "7" */
    0x3f, 0xff, 0xff, 0xff, 0xf8, 0x18, 0x88, 0x88,
    0x8c, 0xf5, 0x0, 0x0, 0x0, 0xe, 0xe0, 0x0,
    0x0, 0x0, 0x6f, 0x70, 0x0, 0x0, 0x0, 0xde,
    0x0, 0x0, 0x0, 0x5, 0xf8, 0x0, 0x0, 0x0,
    0xc, 0xf1, 0x0, 0x0, 0x0, 0x4f, 0x90, 0x0,
    0x0, 0x0, 0xcf, 0x20, 0x0, 0x0, 0x3, 0xfa,
    0x0, 0x0, 0x0, 0xb, 0xf3, 0x0, 0x0, 0x0,
    0x3f, 0xb0, 0x0, 0x0, 0x0, 0xaf, 0x40, 0x0,
    0x0,

    /* U+0038 "8" */
    0x0, 0x19, 0xef, 0xea, 0x20, 0x0, 0x1e, 0xfa,
    0x8a, 0xfe, 0x10, 0x8, 0xf7, 0x0, 0x7, 0xf8,
    0x0, 0x8f, 0x50, 0x0, 0x4f, 0x90, 0x2, 0xfe,
    0x52, 0x4d, 0xf3, 0x0, 0x4, 0xff, 0xff, 0xf5,
    0x0, 0x3, 0xfe, 0x85, 0x7e, 0xf3, 0x0, 0xdf,
    0x30, 0x0, 0x2f, 0xd0, 0x1f, 0xd0, 0x0, 0x0,
    0xcf, 0x11, 0xfd, 0x0, 0x0, 0xc, 0xf1, 0xd,
    0xf5, 0x0, 0x4, 0xfd, 0x0, 0x3f, 0xfb, 0x8a,
    0xff, 0x30, 0x0, 0x29, 0xef, 0xea, 0x20, 0x0,

    /* U+0039 "9" */
    0x0, 0x4b, 0xef, 0xd7, 0x0, 0x6, 0xff, 0xa9,
    0xdf, 0xb0, 0xf, 0xf2, 0x0, 0xb, 0xf5, 0x4f,
    0xa0, 0x0, 0x4, 0xfa, 0x5f, 0x90, 0x0, 0x3,
    0xfb, 0x3f, 0xc0, 0x0, 0x7, 0xf9, 0xd, 0xf9,
    0x10, 0x5f, 0xf5, 0x2, 0xdf, 0xff, 0xff, 0xd0,
    0x0, 0x5, 0x76, 0xaf, 0x40, 0x0, 0x0, 0x5,
    0xf8, 0x0, 0x0, 0x0, 0x3f, 0xc0, 0x0, 0x0,
    0x1, 0xee, 0x20, 0x0, 0x0, 0xc, 0xf5, 0x0,
    0x0,

    /* U+0041 "A" */
    0x0, 0x0, 0xf, 0xfa, 0x0, 0x0, 0x0, 0x0,
    0x6, 0xff, 0xf1, 0x0, 0x0, 0x0, 0x0, 0xcf,
    0x9f, 0x60, 0x0, 0x0, 0x0, 0x3f, 0xa2, 0xfc,
    0x0, 0x0, 0x0, 0x9, 0xf4, 0xc, 0xf2, 0x0,
    0x0, 0x0, 0xee, 0x0, 0x6f, 0x90, 0x0, 0x0,
    0x5f, 0x80, 0x1, 0xfe, 0x0, 0x0, 0xc, 0xf2,
    0x0, 0xa, 0xf5, 0x0, 0x2, 0xff, 0xff, 0xff,
    0xff, 0xb0, 0x0, 0x8f, 0xb9, 0x99, 0x99, 0xef,
    0x10, 0xe, 0xf1, 0x0, 0x0, 0x9, 0xf8, 0x4,
    0xfa, 0x0, 0x0, 0x0, 0x2f, 0xe0, 0xbf, 0x30,
    0x0, 0x0, 0x0, 0xcf, 0x40,

    /* U+0044 "D" */
    0xcf, 0xff, 0xfe, 0xc7, 0x10, 0x0, 0xcf, 0x97,
    0x79, 0xdf, 0xe4, 0x0, 0xcf, 0x20, 0x0, 0x6,
    0xff, 0x20, 0xcf, 0x20, 0x0, 0x0, 0x8f, 0xa0,
    0xcf, 0x20, 0x0, 0x0, 0x1f, 0xf0, 0xcf, 0x20,
    0x0, 0x0, 0xc, 0xf3, 0xcf, 0x20, 0x0, 0x0,
    0xb, 0xf4, 0xcf, 0x20, 0x0, 0x0, 0xc, 0xf3,
    0xcf, 0x20, 0x0, 0x0, 0xf, 0xf1, 0xcf, 0x20,
    0x0, 0x0, 0x8f, 0xb0, 0xcf, 0x20, 0x0, 0x6,
    0xff, 0x20, 0xcf, 0x87, 0x79, 0xdf, 0xe4, 0x0,
    0xcf, 0xff, 0xfe, 0xc7, 0x10, 0x0,

    /* U+0045 "E" */
    0xcf, 0xff, 0xff, 0xff, 0x7c, 0xfa, 0x99, 0x99,
    0x94, 0xcf, 0x20, 0x0, 0x0, 0xc, 0xf2, 0x0,
    0x0, 0x0, 0xcf, 0x20, 0x0, 0x0, 0xc, 0xf9,
    0x88, 0x88, 0x80, 0xcf, 0xff, 0xff, 0xff, 0x1c,
    0xf2, 0x0, 0x0, 0x0, 0xcf, 0x20, 0x0, 0x0,
    0xc, 0xf2, 0x0, 0x0, 0x0, 0xcf, 0x20, 0x0,
    0x0, 0xc, 0xfa, 0x99, 0x99, 0x94, 0xcf, 0xff,
    0xff, 0xff, 0x70,

    /* U+0046 "F" */
    0xcf, 0xff, 0xff, 0xff, 0x4c, 0xfa, 0x99, 0x99,
    0x92, 0xcf, 0x20, 0x0, 0x0, 0xc, 0xf2, 0x0,
    0x0, 0x0, 0xcf, 0x20, 0x0, 0x0, 0xc, 0xfa,
    0x99, 0x99, 0x70, 0xcf, 0xff, 0xff, 0xfe, 0xc,
    0xf2, 0x0, 0x0, 0x0, 0xcf, 0x20, 0x0, 0x0,
    0xc, 0xf2, 0x0, 0x0, 0x0, 0xcf, 0x20, 0x0,
    0x0, 0xc, 0xf2, 0x0, 0x0, 0x0, 0xcf, 0x20,
    0x0, 0x0, 0x0,

    /* U+0048 "H" */
    0xcf, 0x20, 0x0, 0x0, 0xe, 0xf0, 0xcf, 0x20,
    0x0, 0x0, 0xe, 0xf0, 0xcf, 0x20, 0x0, 0x0,
    0xe, 0xf0, 0xcf, 0x20, 0x0, 0x0, 0xe, 0xf0,
    0xcf, 0x20, 0x0, 0x0, 0xe, 0xf0, 0xcf, 0x98,
    0x88, 0x88, 0x8f, 0xf0, 0xcf, 0xff, 0xff, 0xff,
    0xff, 0xf0, 0xcf, 0x20, 0x0, 0x0, 0xe, 0xf0,
    0xcf, 0x20, 0x0, 0x0, 0xe, 0xf0, 0xcf, 0x20,
    0x0, 0x0, 0xe, 0xf0, 0xcf, 0x20, 0x0, 0x0,
    0xe, 0xf0, 0xcf, 0x20, 0x0, 0x0, 0xe, 0xf0,
    0xcf, 0x20, 0x0, 0x0, 0xe, 0xf0,

    /* U+0049 "I" */
    0xcf, 0x2c, 0xf2, 0xcf, 0x2c, 0xf2, 0xcf, 0x2c,
    0xf2, 0xcf, 0x2c, 0xf2, 0xcf, 0x2c, 0xf2, 0xcf,
    0x2c, 0xf2, 0xcf, 0x20,

    /* U+004D "M" */
    0xcf, 0xb0, 0x0, 0x0, 0x0, 0xe, 0xfb, 0xcf,
    0xf2, 0x0, 0x0, 0x0, 0x4f, 0xfb, 0xcf, 0xf8,
    0x0, 0x0, 0x0, 0xbf, 0xfb, 0xce, 0xee, 0x0,
    0x0, 0x1, 0xfc, 0xfb, 0xce, 0x8f, 0x50, 0x0,
    0x7, 0xf6, 0xfb, 0xce, 0x2f, 0xb0, 0x0, 0xe,
    0xc2, 0xfb, 0xce, 0xc, 0xf2, 0x0, 0x4f, 0x62,
    0xfb, 0xce, 0x5, 0xf8, 0x0, 0xbf, 0x2, 0xfb,
    0xce, 0x0, 0xee, 0x1, 0xf9, 0x2, 0xfb, 0xce,
    0x0, 0x8f, 0x57, 0xf3, 0x2, 0xfb, 0xce, 0x0,
    0x2f, 0xce, 0xc0, 0x2, 0xfb, 0xce, 0x0, 0xb,
    0xff, 0x60, 0x2, 0xfb, 0xce, 0x0, 0x5, 0xff,
    0x0, 0x2, 0xfb,

    /* U+004E "N" */
    0xcf, 0xa0, 0x0, 0x0, 0xb, 0xf1, 0xcf, 0xf6,
    0x0, 0x0, 0xb, 0xf1, 0xcf, 0xff, 0x20, 0x0,
    0xb, 0xf1, 0xcf, 0x8f, 0xc0, 0x0, 0xb, 0xf1,
    0xcf, 0xc, 0xf8, 0x0, 0xb, 0xf1, 0xcf, 0x1,
    0xef, 0x40, 0xb, 0xf1, 0xcf, 0x0, 0x5f, 0xe1,
    0xb, 0xf1, 0xcf, 0x0, 0x9, 0xfb, 0xb, 0xf1,
    0xcf, 0x0, 0x0, 0xdf, 0x6b, 0xf1, 0xcf, 0x0,
    0x0, 0x2f, 0xfd, 0xf1, 0xcf, 0x0, 0x0, 0x6,
    0xff, 0xf1, 0xcf, 0x0, 0x0, 0x0, 0xbf, 0xf1,
    0xcf, 0x0, 0x0, 0x0, 0x1e, 0xf1,

    /* U+004F "O" */
    0x0, 0x1, 0x8d, 0xfe, 0xc6, 0x0, 0x0, 0x0,
    0x3e, 0xfc, 0x99, 0xef, 0xc1, 0x0, 0x1, 0xef,
    0x60, 0x0, 0x9, 0xfc, 0x0, 0x9, 0xf9, 0x0,
    0x0, 0x0, 0xcf, 0x60, 0xf, 0xf2, 0x0, 0x0,
    0x0, 0x5f, 0xb0, 0x2f, 0xe0, 0x0, 0x0, 0x0,
    0x1f, 0xe0, 0x3f, 0xd0, 0x0, 0x0, 0x0, 0xf,
    0xf0, 0x2f, 0xe0, 0x0, 0x0, 0x0, 0x1f, 0xe0,
    0xf, 0xf1, 0x0, 0x0, 0x0, 0x5f, 0xb0, 0x9,
    0xf8, 0x0, 0x0, 0x0, 0xcf, 0x60, 0x1, 0xef,
    0x60, 0x0, 0x9, 0xfc, 0x0, 0x0, 0x3e, 0xfc,
    0x99, 0xef, 0xc1, 0x0, 0x0, 0x1, 0x8d, 0xfe,
    0xc6, 0x0, 0x0,

    /* U+0052 "R" */
    0xcf, 0xff, 0xfe, 0xc6, 0x0, 0xc, 0xf8, 0x77,
    0x9e, 0xfb, 0x0, 0xcf, 0x20, 0x0, 0x1e, 0xf3,
    0xc, 0xf2, 0x0, 0x0, 0xaf, 0x60, 0xcf, 0x20,
    0x0, 0xc, 0xf4, 0xc, 0xf3, 0x22, 0x4a, 0xfd,
    0x0, 0xcf, 0xff, 0xff, 0xfc, 0x20, 0xc, 0xf6,
    0x57, 0xfd, 0x0, 0x0, 0xcf, 0x20, 0xa, 0xf8,
    0x0, 0xc, 0xf2, 0x0, 0x1e, 0xf3, 0x0, 0xcf,
    0x20, 0x0, 0x6f, 0xd0, 0xc, 0xf2, 0x0, 0x0,
    0xbf, 0x90, 0xcf, 0x20, 0x0, 0x2, 0xff, 0x30,

    /* U+0053 "S" */
    0x0, 0x5b, 0xef, 0xd9, 0x20, 0x0, 0x9f, 0xfa,
    0xac, 0xfe, 0x20, 0x2f, 0xe1, 0x0, 0x5, 0xf7,
    0x4, 0xfb, 0x0, 0x0, 0x1, 0x0, 0x2f, 0xf4,
    0x0, 0x0, 0x0, 0x0, 0x9f, 0xfc, 0x73, 0x0,
    0x0, 0x0, 0x5b, 0xff, 0xfe, 0x80, 0x0, 0x0,
    0x0, 0x38, 0xff, 0x80, 0x0, 0x0, 0x0, 0x3,
    0xff, 0x0, 0x62, 0x0, 0x0, 0xf, 0xf0, 0x4f,
    0xc1, 0x0, 0x6, 0xfd, 0x0, 0xaf, 0xfb, 0x9c,
    0xff, 0x40, 0x0, 0x5b, 0xef, 0xda, 0x20, 0x0,

    /* U+0054 "T" */
    0x9f, 0xff, 0xff, 0xff, 0xfd, 0x59, 0x99, 0xef,
    0x99, 0x97, 0x0, 0x0, 0xdf, 0x10, 0x0, 0x0,
    0x0, 0xdf, 0x10, 0x0, 0x0, 0x0, 0xdf, 0x10,
    0x0, 0x0, 0x0, 0xdf, 0x10, 0x0, 0x0, 0x0,
    0xdf, 0x10, 0x0, 0x0, 0x0, 0xdf, 0x10, 0x0,
    0x0, 0x0, 0xdf, 0x10, 0x0, 0x0, 0x0, 0xdf,
    0x10, 0x0, 0x0, 0x0, 0xdf, 0x10, 0x0, 0x0,
    0x0, 0xdf, 0x10, 0x0, 0x0, 0x0, 0xdf, 0x10,
    0x0,

    /* U+0055 "U" */
    0xdf, 0x0, 0x0, 0x0, 0xe, 0xfd, 0xf0, 0x0,
    0x0, 0x0, 0xef, 0xdf, 0x0, 0x0, 0x0, 0xe,
    0xfd, 0xf0, 0x0, 0x0, 0x0, 0xef, 0xdf, 0x0,
    0x0, 0x0, 0xe, 0xfd, 0xf0, 0x0, 0x0, 0x0,
    0xef, 0xdf, 0x0, 0x0, 0x0, 0xe, 0xfd, 0xf0,
    0x0, 0x0, 0x0, 0xff, 0xcf, 0x10, 0x0, 0x0,
    0xf, 0xe9, 0xf5, 0x0, 0x0, 0x5, 0xfc, 0x3f,
    0xe2, 0x0, 0x2, 0xdf, 0x50, 0x7f, 0xfb, 0x9b,
    0xff, 0x90, 0x0, 0x4a, 0xef, 0xeb, 0x50, 0x0,

    /* U+0057 "W" */
    0xaf, 0x60, 0x0, 0x0, 0xff, 0x40, 0x0, 0x1,
    0xfc, 0x5f, 0xa0, 0x0, 0x4, 0xff, 0x80, 0x0,
    0x6, 0xf7, 0x1f, 0xe0, 0x0, 0x9, 0xfe, 0xd0,
    0x0, 0xa, 0xf3, 0xc, 0xf3, 0x0, 0xd, 0xc9,
    0xf2, 0x0, 0xe, 0xe0, 0x7, 0xf7, 0x0, 0x2f,
    0x74, 0xf6, 0x0, 0x3f, 0xa0, 0x3, 0xfb, 0x0,
    0x7f, 0x20, 0xfb, 0x0, 0x7f, 0x50, 0x0, 0xef,
    0x0, 0xbe, 0x0, 0xbf, 0x0, 0xbf, 0x10, 0x0,
    0x9f, 0x30, 0xf9, 0x0, 0x6f, 0x50, 0xfc, 0x0,
    0x0, 0x5f, 0x85, 0xf4, 0x0, 0x1f, 0x94, 0xf7,
    0x0, 0x0, 0x1f, 0xc9, 0xf0, 0x0, 0xd, 0xe9,
    0xf3, 0x0, 0x0, 0xc, 0xfe, 0xb0, 0x0, 0x8,
    0xff, 0xe0, 0x0, 0x0, 0x7, 0xff, 0x60, 0x0,
    0x3, 0xff, 0xa0, 0x0, 0x0, 0x3, 0xff, 0x20,
    0x0, 0x0, 0xef, 0x50, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 69, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 97, .box_w = 6, .box_h = 17, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 56, .adv_w = 180, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 121, .adv_w = 123, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 159, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 225, .adv_w = 160, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 290, .adv_w = 172, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 362, .adv_w = 169, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 421, .adv_w = 170, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 486, .adv_w = 162, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 551, .adv_w = 177, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 623, .adv_w = 169, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 688, .adv_w = 202, .box_w = 13, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 773, .adv_w = 209, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 851, .adv_w = 163, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 910, .adv_w = 157, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 969, .adv_w = 212, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1047, .adv_w = 70, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1067, .adv_w = 255, .box_w = 14, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1158, .adv_w = 212, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1236, .adv_w = 221, .box_w = 14, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1327, .adv_w = 186, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1399, .adv_w = 169, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1471, .adv_w = 164, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1536, .adv_w = 210, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1608, .adv_w = 291, .box_w = 18, .box_h = 13, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_1[] = {
    0, 0, 0, 1, 2, 3, 0, 4,
    5, 0, 0, 0, 6, 7, 8, 0,
    0, 9, 10, 11, 12, 0, 13
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 46, .range_length = 12, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 65, .range_length = 23, .glyph_id_start = 13,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_1, .list_length = 23, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 1, 2, 3, 4, 0, 5, 6,
    7, 8, 9, 10, 11, 12, 13, 14,
    15, 0, 0, 0, 0, 13, 16, 17,
    18, 19, 20
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11, 12, 2, 0, 0,
    0, 0, 0, 0, 0, 13, 0, 14,
    15, 16, 17
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, -23, 0, 0, -5, 0,
    -4, -15, 0, -11, 0, 0, 0, 0,
    0, -35, -32, -3, 0, 0, 0, -24,
    -4, -12, 0, -7, -1, -11, 0, 5,
    0, 3, 0, -3, 0, 0, 0, 0,
    0, 0, 0, -10, 0, 0, 0, 0,
    -12, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, 0, 0, -3, 0, -7, 0, -5,
    0, 0, 0, 0, 0, 0, 0, 0,
    -5, 0, 0, 0, -5, 0, -13, 0,
    -5, 0, 0, -10, 0, -8, 0, 0,
    0, -5, 0, 0, 0, 0, -1, -9,
    0, -5, 0, 0, -7, 0, -3, 0,
    0, 0, -14, 0, 0, 0, 0, 0,
    -19, 0, -9, 0, 0, -19, 0, -15,
    -30, -33, -7, 0, 0, 0, -26, -5,
    -18, 2, -6, 0, -10, -2, 0, 0,
    0, 0, -3, 0, -4, 0, 0, 0,
    0, 0, -12, 0, -3, 0, 0, -11,
    0, -3, -17, -19, 0, 0, 0, -2,
    -11, -3, -8, -8, -2, 0, 0, 0,
    0, 0, 0, 6, 0, -3, -17, 0,
    0, -3, 0, 0, -14, -3, -19, -11,
    0, -32, -12, -24, -12, -11, 0, 0,
    -2, 0, 0, 0, 0, -13, 0, 0,
    0, 0, -16, 0, -8, 0, 0, 0,
    0, 0, 0, -7, 0, 0, 0, 0,
    0, -5, 0, 0, 0, 0, -32, -25,
    0, 0, 0, 0, -10, 0, -5, 0,
    0, 0, -2, 0, 0, 0, 3, 10,
    -1, 0, -5, 0, 0, -9, 0, 0,
    -10, 0, 0, -7, -2, -12, -6, -10,
    2, -4, 0, -3, 0, 0, 0, 0,
    0, -5, 0, 0, 0, 0, -7, 0,
    0, -29, -32, -12, 0, 0, 0, -31,
    -10, -25, 0, -11, 0, -16, -1, 1,
    0, 4, -7, -12, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -22, -24, 0, 0, 0,
    0, -18, -4, -13, 0, -3, 0, -8,
    0, 4, 0, 5
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 20,
    .right_class_cnt     = 17,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR >= 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 4,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR >= 8
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t watch_04_font_18 = {
#else
lv_font_t watch_04_font_18 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = NULL,
    .user_data = NULL
};



#endif /*#if WATCH_04_FONT_18*/

