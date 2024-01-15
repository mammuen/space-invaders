#include "joystick.h"
#include "stm32f30x.h"


void joystickinit(){

    ADCsetup();
    buttoninit();

}


void buttoninit(){



	RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port C


	// Set pin PC10 to input
	GPIOC->MODER &= ~(0x00000003 << (10 * 2)); // Clear mode register
	GPIOC->MODER |=  (0x00000000 << (10 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 -Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (10 * 2)); // Clear push/pull register
	GPIOC->PUPDR |=  (0x00000002 << (10 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)

	// Set pin PC12 to input
	GPIOC->MODER &= ~(0x00000003 << (12 * 2)); // Clear mode register
	GPIOC->MODER |=  (0x00000000 << (12 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (12 * 2)); // Clear push/pull register
	GPIOC->PUPDR |=  (0x00000002 << (12 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)




}







void ADCsetup(){

RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port A


// Set pin PC2 to input
GPIOC->MODER &= ~(0x00000003 << (2 * 2)); // Clear mode register
GPIOC->MODER |= (0x00000002 << (2 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 -Alternate Function, 0x03 - Analog in/out)
GPIOC->PUPDR &= ~(0x00000003 << (2 * 2)); // Clear push/pull register
GPIOC->PUPDR |= (0x00000000 << (2 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)

// Set pin PC3 to input
GPIOC->MODER &= ~(0x00000003 << (3 * 2)); // Clear mode register
GPIOC->MODER |=  (0x00000002 << (3 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
GPIOC->PUPDR &= ~(0x00000003 << (3 * 2)); // Clear push/pull register
GPIOC->PUPDR |=  (0x00000000 << (3 * 2)); // Set push/pull register (0x00 - No pull, 0x01 - Pull-up, 0x02 - Pull-down)

// fix time
RCC->CFGR2 &= ~RCC_CFGR2_ADCPRE12; // Clear ADC12 prescaler bits
RCC->CFGR2 |= RCC_CFGR2_ADCPRE12_DIV6; // Set ADC12 prescaler to 6
RCC->AHBENR |= RCC_AHBPeriph_ADC12; // Enable clock for ADC12


//reset ADC
ADC1->CR = 0x00000000; // Clear CR register
ADC1->CFGR &= 0xFDFFC007; // Clear ADC1 config register
ADC1->SQR1 &= ~ADC_SQR1_L; // Clear regular sequence register 1

ADC1->CR |= 0x10000000; // Enable internal ADC voltage regulator
for (int i = 0 ; i < 1000 ; i++) {} // Wait for about 16 microseconds

ADC1->CR |= 0x80000000; // Start ADC1 calibration
//while (!(ADC1->CR & 0x80000000)); // Wait for calibration to finish
for (int i = 0 ; i < 1000 ; i++) {} // Wait for a little while

ADC1->CR |= 0x00000001; // Enable ADC1 (0x01 - Enable, 0x02 - Disable)
while (!(ADC1->ISR & 0x00000001)); // Wait until ready


ADC_StartConversion(ADC1); // Start ADC read

}



uint32_t read_ADC1_9(){

ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 1, ADC_SampleTime_1Cycles5);
ADC_StartConversion(ADC1); // Start ADC read
uint32_t x = ADC_GetConversionValue(ADC1); // Read the ADC value

return x;
}

uint32_t read_ADC1_10(){

ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_1Cycles5);
ADC_StartConversion(ADC1); // Start ADC read
uint32_t x = ADC_GetConversionValue(ADC1); // Read the ADC value

return (x);
}

uint16_t readbtn(int x){
	return (GPIOC->IDR & (0x0001 << x));
}

uint16_t readbtns(){
	uint16_t i = 0;
	i = i + (readbtn(10) >> 10);
	i = i + (readbtn(12) >> 11);
	return i;

}


char readjoystick(){

uint16_t output = 0;
int input = 0;
static int inputprev;

	input = read_ADC1_9();
	if(input > 2500){
		output |= 0x80;
	} else if (input < 1500){
		output |= 0x40;
	}
	input = read_ADC1_10();
	if(input > 2500){
		output |= 0x20;
	} else if (input < 1500){
		output |= 0x10;
	}


	uint8_t a = readbtns();
	if(inputprev != a){
	switch (a) {
	  case 1:
		output |= 0x01;
	    break;
	  case 2:
		output |= 0x02;
		break;
	  case 3:
		output |= 0x03;
	    break;
	  default:
	    // code block
	}
	}
	inputprev = a;


		return output;
}





