﻿#include "LCD.h"

uint8_t lcdControlData;

void LCD_init()
{
	Gpio_initPin(&LCD_CONTROL_DDR,OUTPUT,LCD_RS);
	Gpio_initPin(&LCD_CONTROL_DDR,OUTPUT,LCD_RW);
	Gpio_initPin(&LCD_CONTROL_DDR,OUTPUT,LCD_E);
	Gpio_initPort(&LCD_DATA_DDR,OUTPUT);
	_delay_ms(15);
	LCD_writeCmdData(LCD_FUNCTON_SET);   //
	_delay_ms(5);
	LCD_writeCmdData(LCD_FUNCTON_SET);
	_delay_ms(1);
	LCD_writeCmdData(LCD_FUNCTON_SET);
	LCD_writeCmdData(LCD_FUNCTON_SET);
	LCD_writeCmdData(LCD_DISPLAY_OFF);
	LCD_writeCmdData(LCD_DISPLAY_CLEAR);
	LCD_writeCmdData(LCD_ENTRY_MODE_SET);
	LCD_writeCmdData(LCD_DISPLAY_ON);
}

void LCD_cmdMode()
{
	//RS -> Low
	lcdControlData &= ~(1<<LCD_RS);
	Gpio_WritePort(&LCD_CONTROL_PORT,lcdControlData);
}

void LCD_charMode()
{
	//RS -> High
	lcdControlData |= (1<<LCD_RS);
	Gpio_WritePort(&LCD_CONTROL_PORT,lcdControlData);
}

void LCD_writeMode()
{
	//Rw -> Low
	lcdControlData &= ~(1<<LCD_RW);
	Gpio_WritePort(&LCD_CONTROL_PORT,lcdControlData);
}

void LCD_enableHigh()
{
	lcdControlData |= (1<<LCD_E);
	Gpio_WritePort(&LCD_CONTROL_PORT,lcdControlData);
	_delay_ms(1);
}

void LCD_writeByte(uint8_t data)
{
	Gpio_WritePort(&LCD_DATA_PORT,data);
}

void LCD_enableLow()
{
	lcdControlData &= ~(1<<LCD_E);
	Gpio_WritePort(&LCD_CONTROL_PORT,lcdControlData);
	_delay_ms(1);
}

void LCD_writeCmdData(uint8_t data) // 명령을 내리는 함수
{
	// LCD 내부 명령어 동작
	LCD_cmdMode();
	LCD_writeMode();
	LCD_enableHigh();
	LCD_writeByte(data);
	LCD_enableLow();
}

void LCD_writeCharData(uint8_t data) // 문자를 찍는 함수
{
	// LCD char 쓰는 동작
	LCD_charMode();
	LCD_writeMode();
	LCD_enableHigh();
	LCD_writeByte(data);
	LCD_enableLow();
}

void LCD_writeString(char *str)
{
	for(int i=0;str[i];i++)
	{
		LCD_writeCharData(str[i]);
	}
}

void LCD_gotoXY(uint8_t row, uint8_t col)
{
	col %= 16, row %=2;
	uint8_t lcdregisterAddress = (0x40 * row) +col;
	uint8_t command = 0x80 + lcdregisterAddress;
	LCD_writeCmdData(command);
}

void LCD_writeStringXY(char *str, uint8_t row, uint8_t col)
{
	LCD_gotoXY(row, col);
	LCD_writeString(str);
}