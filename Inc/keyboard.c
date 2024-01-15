/*
 * keyboard.c
 *
 *  Created on: Jan 8, 2024
 *      Author: markus
 */

#include "keyboard.h"

/*

void uart_put_char(uint8_t c);
uint8_t uart_get_char();
uint8_t uart_get_count();
void uart_clear();

*/



char keyboardinput(){

	uint8_t input = uart_get_char();
	char output = 0;

	switch(input){
	case 'w':
		output = 1;
		break;
	case 'a':
		output = 2;
		break;
	case 's':
		output = 3;
		break;
	case 'd':
		output = 4;
		break;
	case ' ':
		output = 10;
		break;
	case 13: //enter key
		output = 0;
		printf("%c[2J", 0x1B);
		break;

	default:
		output = input;
	}
/*
	 the output is like this
	 left "d" = 1000
	 up "w"   = 0100
	 down "s" = 0010
	 right "a"= 0001
	 p outputs 64
	 and enter clears the screen
*/

	return output;
}
