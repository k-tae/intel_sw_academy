﻿#ifndef GPIO_H_
#define GPIO_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

enum {INPUT,OUTPUT};
enum {GPIO_RESET,GPIO_SET};
	
void Gpio_initPort(volatile uint8_t * DDR, uint8_t dir);
void Gpio_initPin(volatile uint8_t * DDR, uint8_t dir, uint8_t pinNum);
void Gpio_WritePort(volatile uint8_t *PORT, uint8_t data);
void Gpio_WritePin(volatile uint8_t *PORT, uint8_t pinNum, uint8_t state);
uint8_t Gpio_ReadPort(volatile uint8_t *PIN);
uint8_t Gpio_ReadPin(volatile uint8_t *PIN, uint8_t pinNum);

#endif /* GPIO_H_ */