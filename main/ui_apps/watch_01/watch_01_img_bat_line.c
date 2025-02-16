#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_WATCH_01_BAT_BG
#define LV_ATTRIBUTE_IMG_WATCH_01_BAT_BG
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_WATCH_01_BAT_BG uint8_t watch_01_bat_bg_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0x25, 0x25, 0x24, 0x92, 0xdb, 0xdb, 0xb6, 
  0x25, 0x24, 0x49, 0xb7, 0xdb, 0xdb, 0x6e, 
  0x25, 0x24, 0x6e, 0xdb, 0xdb, 0xb7, 0x49, 
  0x25, 0x25, 0xb6, 0xdb, 0xdb, 0x92, 0x24, 
  0x24, 0x49, 0xdb, 0xdb, 0xdb, 0x49, 0x24, 
  0x24, 0x92, 0xdb, 0xdb, 0xb6, 0x25, 0x25, 
  0x49, 0xb7, 0xdb, 0xdb, 0x6e, 0x24, 0x25, 
  0x6e, 0xdb, 0xdb, 0xdb, 0x49, 0x24, 0x25, 
  0xb6, 0xdb, 0xdb, 0x92, 0x25, 0x25, 0x25, 
  0x49, 0x25, 0x25, 0x49, 0x49, 0x69, 0x49, 
  0x25, 0x24, 0x25, 0x49, 0x6d, 0x6d, 0x49, 
  0x25, 0x25, 0x49, 0x6d, 0x6d, 0x49, 0x25, 
  0x25, 0x25, 0x49, 0x6d, 0x6d, 0x49, 0x25, 
  0x25, 0x49, 0x69, 0x69, 0x69, 0x49, 0x25, 
  0x25, 0x49, 0x6d, 0x6d, 0x49, 0x25, 0x25, 
  0x25, 0x49, 0x6d, 0x6d, 0x49, 0x25, 0x25, 
  0x49, 0x6d, 0x69, 0x49, 0x25, 0x25, 0x25, 
  0x49, 0x6d, 0x6d, 0x49, 0x25, 0x25, 0x25, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x45, 0x29, 0x25, 0x21, 0xe4, 0x18, 0x10, 0x84, 0x38, 0xc6, 0xf7, 0xbd, 0xd3, 0x9c, 
  0x45, 0x29, 0xe4, 0x18, 0xc7, 0x39, 0x76, 0xb5, 0xd7, 0xbd, 0x39, 0xce, 0x2d, 0x6b, 
  0x45, 0x29, 0xa3, 0x10, 0x4d, 0x6b, 0x38, 0xc6, 0x18, 0xc6, 0x76, 0xb5, 0xa7, 0x39, 
  0x04, 0x21, 0x25, 0x21, 0xd3, 0x9c, 0x18, 0xc6, 0x38, 0xc6, 0x10, 0x84, 0xe4, 0x18, 
  0xc3, 0x18, 0x6a, 0x52, 0xf7, 0xbd, 0xd7, 0xbd, 0xf7, 0xbd, 0x6a, 0x52, 0xc3, 0x18, 
  0xe4, 0x18, 0x10, 0x84, 0x38, 0xc6, 0x18, 0xc6, 0xd3, 0x9c, 0x25, 0x21, 0x04, 0x21, 
  0xa7, 0x39, 0x76, 0xb5, 0x18, 0xc6, 0x38, 0xc6, 0x4d, 0x6b, 0xa3, 0x10, 0x45, 0x29, 
  0x6e, 0x6b, 0x7a, 0xd6, 0x38, 0xc6, 0x96, 0xb5, 0xa7, 0x39, 0xc3, 0x18, 0x25, 0x29, 
  0xb2, 0x94, 0xb6, 0xb5, 0xd7, 0xbd, 0xf0, 0x83, 0x04, 0x21, 0x25, 0x29, 0x66, 0x29, 
  0xa7, 0x39, 0x66, 0x31, 0x86, 0x31, 0x08, 0x42, 0x6a, 0x52, 0x8a, 0x52, 0x29, 0x4a, 
  0x04, 0x21, 0xe4, 0x18, 0x25, 0x21, 0x4a, 0x4a, 0xab, 0x5a, 0xab, 0x5a, 0xe8, 0x39, 
  0x45, 0x29, 0x04, 0x21, 0xc7, 0x39, 0xab, 0x5a, 0x8b, 0x52, 0x6a, 0x52, 0x66, 0x29, 
  0x25, 0x29, 0x45, 0x29, 0x49, 0x4a, 0x8b, 0x52, 0xab, 0x5a, 0x08, 0x42, 0x25, 0x29, 
  0x25, 0x21, 0x87, 0x31, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x87, 0x31, 0x25, 0x21, 
  0x25, 0x29, 0x08, 0x42, 0xab, 0x5a, 0x8b, 0x52, 0x49, 0x4a, 0x45, 0x29, 0x25, 0x29, 
  0x66, 0x29, 0x6a, 0x52, 0x8b, 0x52, 0xab, 0x5a, 0xc7, 0x39, 0x04, 0x21, 0x45, 0x29, 
  0xc7, 0x39, 0xab, 0x5a, 0x8a, 0x52, 0x6a, 0x52, 0x66, 0x31, 0x25, 0x21, 0x45, 0x29, 
  0x49, 0x4a, 0x8a, 0x52, 0xab, 0x5a, 0x08, 0x42, 0x25, 0x21, 0x45, 0x29, 0x45, 0x29, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit BUT the 2 bytes are swapped*/
  0x29, 0x45, 0x21, 0x25, 0x18, 0xe4, 0x84, 0x10, 0xc6, 0x38, 0xbd, 0xf7, 0x9c, 0xd3, 
  0x29, 0x45, 0x18, 0xe4, 0x39, 0xc7, 0xb5, 0x76, 0xbd, 0xd7, 0xce, 0x39, 0x6b, 0x2d, 
  0x29, 0x45, 0x10, 0xa3, 0x6b, 0x4d, 0xc6, 0x38, 0xc6, 0x18, 0xb5, 0x76, 0x39, 0xa7, 
  0x21, 0x04, 0x21, 0x25, 0x9c, 0xd3, 0xc6, 0x18, 0xc6, 0x38, 0x84, 0x10, 0x18, 0xe4, 
  0x18, 0xc3, 0x52, 0x6a, 0xbd, 0xf7, 0xbd, 0xd7, 0xbd, 0xf7, 0x52, 0x6a, 0x18, 0xc3, 
  0x18, 0xe4, 0x84, 0x10, 0xc6, 0x38, 0xc6, 0x18, 0x9c, 0xd3, 0x21, 0x25, 0x21, 0x04, 
  0x39, 0xa7, 0xb5, 0x76, 0xc6, 0x18, 0xc6, 0x38, 0x6b, 0x4d, 0x10, 0xa3, 0x29, 0x45, 
  0x6b, 0x6e, 0xd6, 0x7a, 0xc6, 0x38, 0xb5, 0x96, 0x39, 0xa7, 0x18, 0xc3, 0x29, 0x25, 
  0x94, 0xb2, 0xb5, 0xb6, 0xbd, 0xd7, 0x83, 0xf0, 0x21, 0x04, 0x29, 0x25, 0x29, 0x66, 
  0x39, 0xa7, 0x31, 0x66, 0x31, 0x86, 0x42, 0x08, 0x52, 0x6a, 0x52, 0x8a, 0x4a, 0x29, 
  0x21, 0x04, 0x18, 0xe4, 0x21, 0x25, 0x4a, 0x4a, 0x5a, 0xab, 0x5a, 0xab, 0x39, 0xe8, 
  0x29, 0x45, 0x21, 0x04, 0x39, 0xc7, 0x5a, 0xab, 0x52, 0x8b, 0x52, 0x6a, 0x29, 0x66, 
  0x29, 0x25, 0x29, 0x45, 0x4a, 0x49, 0x52, 0x8b, 0x5a, 0xab, 0x42, 0x08, 0x29, 0x25, 
  0x21, 0x25, 0x31, 0x87, 0x52, 0x8a, 0x52, 0x8a, 0x52, 0x8a, 0x31, 0x87, 0x21, 0x25, 
  0x29, 0x25, 0x42, 0x08, 0x5a, 0xab, 0x52, 0x8b, 0x4a, 0x49, 0x29, 0x45, 0x29, 0x25, 
  0x29, 0x66, 0x52, 0x6a, 0x52, 0x8b, 0x5a, 0xab, 0x39, 0xc7, 0x21, 0x04, 0x29, 0x45, 
  0x39, 0xc7, 0x5a, 0xab, 0x52, 0x8a, 0x52, 0x6a, 0x31, 0x66, 0x21, 0x25, 0x29, 0x45, 
  0x4a, 0x49, 0x52, 0x8a, 0x5a, 0xab, 0x42, 0x08, 0x21, 0x25, 0x29, 0x45, 0x29, 0x45, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format: Fix 0xFF: 8 bit, Red: 8 bit, Green: 8 bit, Blue: 8 bit*/
  0x29, 0x27, 0x27, 0xff, 0x25, 0x23, 0x23, 0xff, 0x1d, 0x1a, 0x1a, 0xff, 0x82, 0x81, 0x81, 0xff, 0xc2, 0xc2, 0xc2, 0xff, 0xba, 0xba, 0xba, 0xff, 0x9a, 0x99, 0x99, 0xff, 
  0x29, 0x27, 0x27, 0xff, 0x1c, 0x1a, 0x1a, 0xff, 0x3b, 0x39, 0x39, 0xff, 0xac, 0xac, 0xac, 0xff, 0xb9, 0xb9, 0xb9, 0xff, 0xc4, 0xc4, 0xc4, 0xff, 0x65, 0x64, 0x64, 0xff, 
  0x2a, 0x28, 0x28, 0xff, 0x15, 0x13, 0x13, 0xff, 0x69, 0x68, 0x68, 0xff, 0xc1, 0xc2, 0xc2, 0xff, 0xbe, 0xbe, 0xbe, 0xff, 0xac, 0xac, 0xac, 0xff, 0x37, 0x35, 0x35, 0xff, 
  0x23, 0x21, 0x21, 0xff, 0x25, 0x22, 0x22, 0xff, 0x97, 0x96, 0x96, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0xc2, 0xc2, 0xc2, 0xff, 0x80, 0x80, 0x80, 0xff, 0x1d, 0x1b, 0x1b, 0xff, 
  0x19, 0x16, 0x16, 0xff, 0x4e, 0x4c, 0x4c, 0xff, 0xb9, 0xba, 0xba, 0xff, 0xb6, 0xb6, 0xb6, 0xff, 0xb9, 0xba, 0xba, 0xff, 0x4e, 0x4c, 0x4c, 0xff, 0x19, 0x16, 0x16, 0xff, 
  0x1d, 0x1b, 0x1b, 0xff, 0x80, 0x7f, 0x7f, 0xff, 0xc2, 0xc2, 0xc2, 0xff, 0xc0, 0xc0, 0xc0, 0xff, 0x97, 0x97, 0x97, 0xff, 0x25, 0x23, 0x23, 0xff, 0x23, 0x21, 0x21, 0xff, 
  0x37, 0x35, 0x35, 0xff, 0xac, 0xac, 0xac, 0xff, 0xbe, 0xbe, 0xbe, 0xff, 0xc1, 0xc2, 0xc2, 0xff, 0x69, 0x68, 0x68, 0xff, 0x15, 0x13, 0x13, 0xff, 0x2a, 0x28, 0x28, 0xff, 
  0x6c, 0x6b, 0x6b, 0xff, 0xcc, 0xcd, 0xcd, 0xff, 0xc3, 0xc3, 0xc3, 0xff, 0xb0, 0xb0, 0xb0, 0xff, 0x37, 0x35, 0x35, 0xff, 0x19, 0x17, 0x17, 0xff, 0x27, 0x25, 0x25, 0xff, 
  0x92, 0x92, 0x92, 0xff, 0xb2, 0xb2, 0xb2, 0xff, 0xb8, 0xb8, 0xb8, 0xff, 0x7e, 0x7d, 0x7d, 0xff, 0x21, 0x1f, 0x1f, 0xff, 0x26, 0x24, 0x24, 0xff, 0x2c, 0x2a, 0x2b, 0xff, 
  0x35, 0x34, 0x34, 0xff, 0x2f, 0x2d, 0x2d, 0xff, 0x30, 0x2e, 0x2e, 0xff, 0x41, 0x3f, 0x40, 0xff, 0x4f, 0x4c, 0x4e, 0xff, 0x51, 0x4e, 0x50, 0xff, 0x47, 0x45, 0x46, 0xff, 
  0x22, 0x20, 0x20, 0xff, 0x1d, 0x1b, 0x1b, 0xff, 0x25, 0x22, 0x22, 0xff, 0x4c, 0x48, 0x4a, 0xff, 0x56, 0x53, 0x55, 0xff, 0x58, 0x55, 0x57, 0xff, 0x3d, 0x3a, 0x3b, 0xff, 
  0x29, 0x27, 0x27, 0xff, 0x23, 0x21, 0x21, 0xff, 0x3b, 0x39, 0x3a, 0xff, 0x55, 0x52, 0x54, 0xff, 0x54, 0x51, 0x53, 0xff, 0x4f, 0x4c, 0x4e, 0xff, 0x2d, 0x2b, 0x2b, 0xff, 
  0x27, 0x25, 0x25, 0xff, 0x28, 0x26, 0x25, 0xff, 0x49, 0x46, 0x47, 0xff, 0x54, 0x51, 0x53, 0xff, 0x55, 0x52, 0x54, 0xff, 0x42, 0x3f, 0x41, 0xff, 0x26, 0x24, 0x24, 0xff, 
  0x24, 0x23, 0x22, 0xff, 0x34, 0x31, 0x32, 0xff, 0x52, 0x4f, 0x51, 0xff, 0x51, 0x4e, 0x50, 0xff, 0x52, 0x4f, 0x51, 0xff, 0x34, 0x31, 0x32, 0xff, 0x24, 0x23, 0x22, 0xff, 
  0x26, 0x24, 0x24, 0xff, 0x42, 0x3f, 0x41, 0xff, 0x55, 0x52, 0x54, 0xff, 0x54, 0x51, 0x53, 0xff, 0x49, 0x46, 0x47, 0xff, 0x28, 0x26, 0x25, 0xff, 0x27, 0x25, 0x25, 0xff, 
  0x2d, 0x2b, 0x2b, 0xff, 0x4f, 0x4c, 0x4e, 0xff, 0x54, 0x51, 0x53, 0xff, 0x55, 0x52, 0x54, 0xff, 0x3b, 0x39, 0x3a, 0xff, 0x23, 0x21, 0x21, 0xff, 0x29, 0x27, 0x27, 0xff, 
  0x3a, 0x38, 0x38, 0xff, 0x55, 0x52, 0x54, 0xff, 0x52, 0x4f, 0x51, 0xff, 0x4f, 0x4c, 0x4e, 0xff, 0x2e, 0x2c, 0x2c, 0xff, 0x25, 0x23, 0x23, 0xff, 0x29, 0x27, 0x27, 0xff, 
  0x49, 0x46, 0x48, 0xff, 0x53, 0x50, 0x52, 0xff, 0x55, 0x52, 0x54, 0xff, 0x42, 0x40, 0x41, 0xff, 0x25, 0x23, 0x23, 0xff, 0x28, 0x26, 0x26, 0xff, 0x29, 0x27, 0x27, 0xff, 
#endif
};

const lv_img_dsc_t watch_01_img_bat_line = {
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 7,
  .header.h = 18,
  .data_size = 126 * LV_COLOR_SIZE / 8,
  .data = watch_01_bat_bg_map,
};
