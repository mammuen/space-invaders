/*
 * timer.c
 *
 *  Created on: Jan 8, 2024
 *      Author: markus
 */

#include "timer.h"
#include "stm32f30x.h"


void timerInit(){

	RCC ->APB2ENR |= RCC_APB2Periph_TIM15;
	TIM15->CR1 = TIM15->CR1 & ~(0x001); 	// turn off timer

	TIM15->ARR = 999; 	// Set reload value

	TIM15->PSC = 639; 	// Set prescale value
	TIM15->DIER |= 0x0001; // enable timer 15's interrutps

	TIM15->CR1 = TIM15->CR1 | (0x001); 	// turn on timer

	NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 5);
	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);

	// calls interrupt ever 1 ms


}

