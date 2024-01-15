#ifndef PROJECT5_H_
#define PROJECT5_H_

#include "stdint.h"
#include "30010_io.h"

void buttoninit();
void joystickinit();
void ADCsetup();
uint32_t read_ADC1_9();
uint32_t read_ADC1_10();
uint16_t readbtn(int x);
uint16_t readbtns();
char readjoystick();

/*
 *
 * to the right
 * 1000 0000
 * to the left
 * 0100 0000
 * to the up
 * 0010 0000
 * to the down
 * 0001 0000
 *
 * sw1 - white
 * 0000 0010
 * sw2 - red
 * 0000 0001
 *
 * */





#endif /* PROJECT5_H_ */
