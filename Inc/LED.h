/*
 * LED.h
 *
 *  Created on: Jan 15, 2024
 *      Author: markus
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f30x.h"

void setLed(int in);
char readJoystick();
int setup();
int readgpioA4();
int readgpioB0();
void onRed(int in);
void onGreen(int in);
void onBlue(int in);
void offRed(int in);
void offGreen(int in);
void offBlue(int in);


#endif /* LED_H_ */
