#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"
#include "charset.h"
#include <stdio.h>
#include <string.h>
<<<<<<< Updated upstream

void drawGameDisplay() {
    Point p1 = {1, 1};
    Point p2 = {180, 50};
    int style = 1;

    drawAsciiWindow(&p1, &p2, style);
}

void showCursor() {
        fputs("\033[?25h", stdout); // Show cursor
    }

void hideCursor() {
	 fputs("\033[?25l", stdout); // Hide cursor
}
=======
#include "game.h"
>>>>>>> Stashed changes

int main(void) {

	//setup
	uart_init(460800);
	hideCursor();


	    while (1) {

	    }
	}

