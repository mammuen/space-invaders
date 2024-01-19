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
void healthLED(int in);
int setup();
int ledsetup();
int readgpioA4();
int readgpioB0();
int readgpioC0();
int readgpioC1();
int readgpioB5();
void onRed(int in);
void onGreen(int in);
void onBlue(int in);
void offRed(int in);
void offGreen(int in);
void offBlue(int in);











#endif /* LED_H_ */
