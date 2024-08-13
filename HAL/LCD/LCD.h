/*
 * LCD.h
 *
 *  Created on: Sep 10, 2022
 *      Author: hp
 */

#ifndef LCD_H_
#define LCD_H_

#include "STD_types.h"
#include "DIO.h"

#define RS PIN_0
#define RW PIN_1
#define E PIN_2
#define LCD_CTRL_PORT PORTC_NUM
#define LCD_DATA_PORT PORTA_NUM

#define CLEAR_DISPLAY 0x01
#define DISPLAY_ON 0x0c
#define DISPLAY_MODE 0x38 //8 bit mode
#define CURSOR_AUTO_INCREMENT 0x06
#define RETURN_HOME 0x80
#define SHIFT_DISPLAY_RIGHT 0x1c
#define SHIFT_DISPLAY_LEFT 0x18
#define  SEC_LINE 0xC0

void LCD_SEND_COMMAND(u8 COMMAND);
void LCD_INIT(void);
void  LCD_SEND_DATA(u8 DATA);
void LCD_String (u8 *str);

#endif /* LCD_H_ */
