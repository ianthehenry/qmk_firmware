#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    g Heavy Industries
#define PRODUCT     		FaunchPad
#define DESCRIPTION     Teeny Toiny Macropad
#define VERSION 				"Rev 1"

#define FORCE_NKRO

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 4
#define MATRIX_ROW_PINS { F4, F5 }
#define MATRIX_COL_PINS { B3, B2, B1, B0}

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION ROW2COL

#define USB_MAX_POWER_CONSUMPTION 50
