﻿#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "../../periph/GPIO/GPIO.h"

#ifndef LCD_H_
#define LCD_H_


#define		LCD_CONTROL_DDR		DDRB
#define		LCD_DATA_DDR		DDRC
#define		LCD_CONTROL_PORT	PORTB
#define		LCD_DATA_PORT		PORTC
#define		LCD_RS				5
#define		LCD_RW				6
#define		LCD_E				7
#define		LCD_FUNCTON_SET		0x38
#define		LCD_DISPLAY_OFF		0x08
#define		LCD_DISPLAY_CLEAR	0x01
#define		LCD_ENTRY_MODE_SET	0x06
#define		LCD_DISPLAY_ON		0x0C

void GPIO_init();
void LCD_init();
void LCD_cmdMode();
void LCD_charMode();
void LCD_writeMode();
void LCD_enableHigh();
void LCD_writeByte(uint8_t data);
void LCD_enableLow();
void LCD_writeCmdData(uint8_t data);
void LCD_writeCharData(uint8_t data);
void LCD_writeString(char *str);
void LCD_gotoXY(uint8_t row, uint8_t col);
void LCD_writeStringXY(char *str, uint8_t row, uint8_t col);


#endif /* LCD_H_ */