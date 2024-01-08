/*
 * LCDdisplay.h
 *
 *  Created on: Jan 8, 2024
 *      Author: markus
 */

#ifndef LCDDISPLAY_H_
#define LCDDISPLAY_H_

#include <stdint.h>


void displayString(uint8_t* array, int x, int y);
extern const char character_data[95][5];


#endif /* LCDDISPLAY_H_ */
