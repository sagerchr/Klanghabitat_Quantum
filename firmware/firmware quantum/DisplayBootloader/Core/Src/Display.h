/*
 * Display.h
 *
 *  Created on: 25 Aug 2020
 *      Author: christiansager
 */

#ifndef SRC_DISPLAY_H_
#define SRC_DISPLAY_H_

#include "stm32469i_discovery.h"
#include "stm32469i_discovery_lcd.h"
#include "stm32469i_discovery_ts.h"
#include "stm32469i_discovery_sdram.h"

#include <stdlib.h>
#include <stdio.h>
/* Alias for LCD_FB_START_ADDRESS : frame buffer displayed on LCD */
#define LCD_FRAME_BUFFER              LCD_FB_START_ADDRESS

#define WVGA_RES_X                    800
#define WVGA_RES_Y                    480

#define LCD_SCREEN_WIDTH              WVGA_RES_X
#define LCD_SCREEN_HEIGHT             WVGA_RES_Y

#define ARGB8888_BYTE_PER_PIXEL       4
#define RGB888_BYTE_PER_PIXEL         3

/* Buffer LCD Converted to RGB888 in SDRAM in order to be copied to SD Card   */
/* Starts directly at end of LCD frame buffer                                 */
#define CONVERTED_FRAME_BUFFER        LCD_FRAME_BUFFER + (LCD_SCREEN_WIDTH * LCD_SCREEN_HEIGHT * ARGB8888_BYTE_PER_PIXEL)




#endif /* SRC_DISPLAY_H_ */
