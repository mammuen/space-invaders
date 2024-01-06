#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"
#include "charset.h"
#include <stdio.h>
#include <string.h>

void drawGameDisplay() {
    Point p1 = {5, 5};
    Point p2 = {15, 10};
    int style = 1;

    drawAsciiWindow(&p1, &p2, style);
}

void showCursor() {
        fputs("\033[?25h", stdout); // Show cursor
    }

void hideCursor() {
	 fputs("\033[?25l", stdout); // Hide cursor
}

int main(void) {

	//setup
	uart_init(460800);
	hideCursor();

	//variables
	int c = 0;

	//main loop
	while (1) {


		drawGameDisplay();

		//clear the screen
		if(c%1000 == 0) {
			clrscr();
		}

		if (c == 10000000000) {
			c = 0;
		} else {
			c++;
		}
	}

}
