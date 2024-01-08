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

extern char heart[5];
void displayString(uint8_t* array, int x, int y);
extern const char character_data[95][5];
void drawHearts(uint8_t num, uint8_t x, uint8_t y);


#endif /* LCDDISPLAY_H_ */
