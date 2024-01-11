/*
 * LCDdisplay.h
 *
 *  Created on: Jan 8, 2024
 *      Author: markus
 */

#ifndef LCDDISPLAY_H_
#define LCDDISPLAY_H_

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h"
#include <stdlib.h>

uint8_t* initalize_LCD();

void LCD_gameStart(uint8_t* LCD);

void stringAdd(uint8_t* LCD, char* text, uint8_t x, uint8_t y);

extern const char character_data[99][5];
void drawHearts(uint8_t num, uint8_t x, uint8_t y);
void setScore(uint8_t* LCD,  uint8_t amount);



void bulletamount(uint8_t* LCD, uint8_t amount);

void bullet0(uint8_t* LCD);
void bullet1(uint8_t* LCD);
void bullet2(uint8_t* LCD);
void bullet3(uint8_t* LCD);
void bullet4(uint8_t* LCD);
void bullet5(uint8_t* LCD);
//void bullet0(uint8_t* LCD)

void healthamount(uint8_t* LCD, uint8_t amount);

void heart0(uint8_t* LCD);
void heart1(uint8_t* LCD);
void heart2(uint8_t* LCD);
void heart3(uint8_t* LCD);

void LCDclrline(uint8_t *LCD,uint8_t liney);

void LCDclrscrn(uint8_t *LCD,uint8_t fill);

#endif /* LCDDISPLAY_H_ */
