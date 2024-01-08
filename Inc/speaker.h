/*
 * Speaker.h
 *
 *  Created on: Jan 8, 2024
 *      Author: markus
 */

#ifndef SPEAKER_H_
#define SPEAKER_H_


#include "stm32f30x.h"
#include "stm32f30x_conf.h"


void speakerSetup();
void setFreq(uint16_t freq);

#endif /* SPEAKER_H_ */
