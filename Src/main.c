#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"
#include "charset.h"
#include "game.h"
#include "menu.h"
#include "LCDdisplay.h"
#include <stdio.h>
#include <string.h>
#include "joystick.h"


#include "LCDdisplay.h"
#include "game.h"



int main(void) {

	//setup
	uart_init(460800);
	hideCursor();
	setup();
	selectMenu();


	    while (1) {


	    }
	}

