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


void stringAdd(uint8_t* LCD, char* text, uint8_t x, uint8_t y);

void displayString(uint8_t* array, int x, int y);
extern const char character_data[99][5];
void drawHearts(uint8_t num, uint8_t x, uint8_t y);



void LCDclrscrn(uint8_t *LCD,uint8_t fill);
uint8_t* initalize_LCD();

#endif /* LCDDISPLAY_H_ */
