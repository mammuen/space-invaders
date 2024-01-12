#include "ansi.h"
#include <stdio.h>
#include <string.h>
#include "game.h"
#include <stdlib.h>

void drawGameDisplay(Window win) {
	int w = win.w;
	int h = win.h;
    Point p1 = {1, 1};
    Point p2 = {w, h};
    int style = 1;

    drawAsciiWindow(&p1, &p2, style);
}

void showCursor() {
     fputs("\033[?25h", stdout); // Show cursor
}

void hideCursor() {
	 fputs("\033[?25l", stdout); // Hide cursor
}

void getKeystrokes() {

}

void drawAsteroid() {

}

void updateAsteroid() {

}

void initAsteroid() {

}

void drawStars() {

}
