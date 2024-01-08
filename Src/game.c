/*
 * game.c
 *
 *  Created on: 8 Jan 2024
 *      Author: oscar
 */

#include "ansi.h"
#include <stdio.h>
#include <string.h>

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

void drawPlayer() {

}

void updatePlayer() {

}

void getKeystrokes() {

}

void drawAsteroid() {

}

void updateAsteroid() {

}

void initAsteroid() {

}
