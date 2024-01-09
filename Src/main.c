#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"
#include "charset.h"
#include "game.h"
#include "menu.h"
#include "LCDdisplay.h"
#include <stdio.h>
#include <string.h>


#include "LCDdisplay.h"
#include "game.h"



int main(void) {

	//setup
	uart_init(460800);
	hideCursor();

	//variables
	int count = 0;

	while (1) {

		drawGameDisplay();

		if (count % 100 == 1) {
			clrscr();
		}

		if (count > 1000000000) {
			count = 0;
		}
		count += 1;
	}
}

