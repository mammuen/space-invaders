#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"
#include "charset.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	uart_init(9600);
	printf("Hello World!\n");
	while(1){}
}
