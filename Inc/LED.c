/*
 * project5.c
 *
 *  Created on: Jan 15, 2024
 *      Author: markus
 */

#include "LED.h"

char readJoystick(){
		char up = readgpioA4() >> 1;
		char down = readgpioB0() << 1;
		char left = readgpioC1() << 1;
		char right = readgpioC0();
		char center = readgpioB5() >> 1;

		char output = up | down | left | right | center;
		return output;
}



void healthLED(int in){

	switch(in){

	case 0:
		//no light
		onRed(1);
		onGreen(1);
		onBlue(1);
		break;
	case 1:
		//red light
		offRed(1);
		onGreen(1);
		onBlue(1);
		break;
	case 2:
		onRed(1);
		offGreen(1);
		onBlue(1);
		//green light
		break;
	case 3:
		offRed(1);
		offGreen(1);
		offBlue(1);
		//white light
		break;
	default:
		offRed(1);
		offGreen(1);
		offBlue(1);
		//white light
		break;

	}

}





int ledsetup(){

	// set PA9 to output
	int pin = 9;
	GPIOA->OSPEEDR &= ~(0x00000003 << (pin * 2)); // Clear speed register
	GPIOA->OSPEEDR |= (0x00000002 << (pin * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)

	GPIOA->OTYPER &= ~(0x0001 << (pin * 1)); // Clear output type register
	GPIOA->OTYPER |= (0x0000 << (pin)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)

	GPIOA->MODER &= ~(0x00000003 << (pin * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000001 << (pin * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

	// set PC7 to output
	pin = 7;
	GPIOC->OSPEEDR &= ~(0x00000003 << (pin * 2)); // Clear speed register
	GPIOC->OSPEEDR |= (0x00000002 << (pin * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)

	GPIOC->OTYPER &= ~(0x0001 << (pin * 1)); // Clear output type register
	GPIOC->OTYPER |= (0x0000 << (pin)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)

	GPIOC->MODER &= ~(0x00000003 << (pin * 2)); // Clear mode register
	GPIOC->MODER |= (0x00000001 << (pin * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

	// set PB4 to output
	pin = 4;
	GPIOB->OSPEEDR &= ~(0x00000003 << (pin * 2)); // Clear speed register
	GPIOB->OSPEEDR |= (0x00000002 << (pin * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)

	GPIOB->OTYPER &= ~(0x0001 << (pin * 1)); // Clear output type register
	GPIOB->OTYPER |= (0x0000 << (pin)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)

	GPIOB->MODER &= ~(0x00000003 << (pin * 2)); // Clear mode register
	GPIOB->MODER |= (0x00000001 << (pin * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

}

int setup(){

	RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A
	RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B
	RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port C




	// Set pin PA4 to input
	GPIOA->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000000 << (4 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02	// Alternate Function, 0x03 - Analog in/out)
	GPIOA->PUPDR &= ~(0x00000003 << (4 * 2)); // Clear push/pull register
	GPIOA->PUPDR |= (0x00000002 << (4 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)
	// Set pin PB0 to input
	GPIOB->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
	GPIOB->MODER |= (0x00000000 << (0 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02	// Alternate Function, 0x03 - Analog in/out)
	GPIOB->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
	GPIOB->PUPDR |= (0x00000002 << (0 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)


	// Set pin PC1 and PC0 to input
	GPIOC->MODER &= ~(0x0000000f << (0 * 2)); // Clear mode register for the first 4 bit
	GPIOC->MODER |= (0x00000000 << (0 * 2)); // Set mode register
	//(0x00 –Input, 0x01 - Output, 0x02	// Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x0000000f << (0 * 2)); // Clear push/pull register
	GPIOC->PUPDR |= (0x0000000c << (0 * 2)); // Set push/pull register
	//(0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)


	// Set pin PB5 to input
	GPIOB->MODER &= ~(0x00000003 << (5 * 2)); // Clear mode register
	GPIOB->MODER |= (0x00000000 << (5 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02	// Alternate Function, 0x03 - Analog in/out)
	GPIOB->PUPDR &= ~(0x00000003 << (5 * 2)); // Clear push/pull register
	GPIOB->PUPDR |= (0x00000002 << (5 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)






/*
	// Set pin PA1 to output
	GPIOA->OSPEEDR &= ~(0x00000003 << (1 * 2)); // Clear speed register
	GPIOA->OSPEEDR |= (0x00000002 << (1 * 2)); // set speed register (0x01 - 10MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
	GPIOA->OTYPER &= ~(0x0001 << (pin * 1)); // Clear output type register
	GPIOA->OTYPER |= (0x0000 << (1)); // Set output type register (0x00 -Push pull, 0x01 - Open drain)
	GPIOA->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000001 << (1 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOA->ODR |= (0x0001 << 1); //Set pin PA1 to high
*/
return 0;
}



void setLed(int in){

	/* if input is 1 then the red led pulls low turning the led on
	 * if input is 2 then the blue turns on
	 * if input is 4 then the green turns on
	 * if input is 8 then the white light turns on
	 */

	if(in == 1){
		offRed(3);
	} else {
		onRed(3);
	}

	if(in == 2){
		offBlue(1);
	} else {
		onBlue(3);
	}
	if(in == 4){
		offGreen(2);
	} else {
		onGreen(2);
	}

	if(in == 8){
		offBlue(1);
		offRed(1);
		offGreen(1);
	}

}




// set PC7 to output
// set PB4 to output


void onRed(int in){
	GPIOB->ODR |= (0x0001 << 4); //Set pin PA1 to high
}

void onGreen(int in){
	GPIOC->ODR |= (0x0001 << 7); //Set pin PA1 to high
}

void onBlue(int in){
	GPIOA->ODR |= (0x0001 << 9); //Set pin PA1 to high
}



void offRed(int in){
	GPIOB->ODR &= ~(0x0001 << 4); //Set pin PA1 to low
}

void offGreen(int in){
	GPIOC->ODR &= ~(0x0001 << 7); //Set pin PA1 to low
}

void offBlue(int in){
	GPIOA->ODR &= ~(0x0001 << 9); //Set pin PA1 to low
}






int readgpioA4(){

	char val = GPIOA->IDR & (0x0001 << 4); //Read from pin PA4

	return val;
}
int readgpioB0(){

	char val = GPIOB->IDR & (0x0001 << 0); //Read from pin PB0

	return val;
}
// Set pin PB5 to input

int readgpioC0(){

	char val = GPIOC->IDR & (0x0001 << 0); //Read from pin PB0

	return val;
}
int readgpioC1(){

	char val = GPIOC->IDR & (0x0001 << 1); //Read from pin PB0

	return val;
}

int readgpioB5(){

	char val = GPIOB->IDR & (0x0001 << 5); //Read from pin PB0

	return val;
}



