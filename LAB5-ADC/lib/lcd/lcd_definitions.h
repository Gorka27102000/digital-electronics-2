#ifndef LCD_DEFINITIONS_H
# define LCD_DEFINITIONS_H

/***********************************************************************
 * 
 * Adjusting the display settings. All definitions added to the file 
 * "lcd_definitions.h" will override the default definitions from 
 * "lcd.h" (see Peter Fleury's LCD library for HD44780 based LCDs).
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019 Tomas Fryza, Peter Fleury
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 * @file 
 * @defgroup fryza_lcd LCD Definitions <lcd_definitions.h>
 * @code #include "lcd_definitions.h" @endcode
 *
 * @brief Adjusting the display settings.
 *
 * All definitions added to the file "lcd_definitions.h" will override 
 * the default definitions from "lcd.h" (see Peter Fleury's LCD library
 * for HD44780 based LCDs).
 *
 * @author Tomas Fryza, Peter Fleury, Dept. of Radio Electronics,
 *         Brno University of Technology, Czechia
 * @copyright (c) 2019 Tomas Fryza, Peter Fleury, This work is 
 *                licensed under the terms of the MIT license
 * @{
 */


/* Defines -----------------------------------------------------------*/
/**
 * @name  Definitions for Display Size
 * Number of visible lines and characters per line of the display.
 *
 * @note All definitions added to the file lcd_definitions.h will 
 * override the default definitions from lcd.h. Add -D_LCD_DEFINITIONS_FILE
 * to the CDEFS section in the Makefile.
 */
#define LCD_LINES 2  /**< @brief Number of visible lines of the display */
#define LCD_DISP_LENGTH 16  /**< @brief Visibles characters per line of the display */


/**