/*
 * speaker.c
 *
 *  Created on: Jan 8, 2024
 *      Author: markus
 */

#include "speaker.h"
#define PRESCALE 0x0010
#define RELOAD 0x0010


void speakerSetup(){

//configure timer2
RCC->APB1ENR |= RCC_APB1Periph_TIM2; // Enable clock line to timer 2;
TIM2->CR1 = TIM2->CR1 & ~(0x0003 << 5 ); // edge aligned mode

TIM2->ARR = RELOAD; // Set reload value to 16
TIM2->PSC = PRESCALE; // Set prescale value

TIM2->CCER &= ~TIM_CCER_CC3P; // Clear CCER register
TIM2->CCER |= 0x00000001 << 8; // Enable OC3 output
TIM2->CCMR2 &= ~TIM_CCMR2_OC3M; // Clear CCMR2 register
TIM2->CCMR2 &= ~TIM_CCMR2_CC3S;
TIM2->CCMR2 |= TIM_OCMode_PWM1; // Set output mode to PWM1
TIM2->CCMR2 &= ~TIM_CCMR2_OC3PE;
TIM2->CCMR2 |= TIM_OCPreload_Enable;
TIM2->CCR3 = 0x0010 / 2; // Set duty cycle to 50 %

TIM2->CR1 |= 0x0001; //enable timer


RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B

// set PB10 to output
int pin = 10;
GPIOB->OSPEEDR &= ~(0x00000003 << (pin * 2)); // Clear speed register
GPIOB->OSPEEDR |= (0x00000001 << (pin * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
GPIOB->OTYPER &= ~(0x0001 << (pin * 1)); // Clear output type register
GPIOB->OTYPER |= (0x0000 << (pin)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
GPIOB->MODER &= ~(0x00000003 << (pin * 2)); // Clear mode register
GPIOB->MODER |= (0x00000002 << (pin * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)


GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_1);

}




void setFreq(uint16_t freq) {

uint32_t reload = 64e6 / freq / (PRESCALE + 1) - 1;
TIM2->ARR = reload; // Set auto reload value
TIM2->CCR3 = reload/2; // Set compare register
TIM2->EGR |= 0x01;

}






