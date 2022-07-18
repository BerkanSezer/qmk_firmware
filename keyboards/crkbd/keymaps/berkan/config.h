#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

// #define TAPPING_FORCE_HOLD
// #define TAPPING_TERM 100
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"


// Size optimisations
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

#define NO_ACTION_MACRO
#define NO_ACTION_ONESHOT
#define NO_ACTION_FUNCTION
// Size optimisations

#define SPLIT_USB_DETECT
