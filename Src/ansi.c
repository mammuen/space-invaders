/*
 * ansi.c
 *
 *  Created on: 5 Jan 2024
 *      Author: oscar
 */

#define ESC 0x1B

#include "ansi.h"
#include <stdio.h>


void fgcolor(uint8_t foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(uint8_t background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(uint8_t foreground, uint8_t background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);
}

void clrscr() {
	printf("%c[2J", ESC);
}

void clreol() {
	printf("%c[K", ESC);
}


void gotoxy(uint8_t x, uint8_t y){
	printf("%c[%d;%dH", ESC, y, x);
}

void underline(uint8_t on){
	if (on){
	printf("%c[4m", ESC);
	}
	else {
	printf("%c[24m", ESC);
	}
}

void blink(uint8_t on){
	if (on){
	printf("%c[5m", ESC);
	}
	else {
	printf("%c[25m", ESC);
	}

}
void inverse(uint8_t on){
	if (on){
	printf("%c[7m", ESC);
	}
	else {
	printf("%c[27m", ESC);
	}
}


void drawAsciiWindow(Point *point1, Point *point2 , int style) {
	//draw an ascii window in the terminal
	int x1 = point1->x;
	int x2 = point2->x;
	int y1 = point1->y;
	int y2 = point2->y;
	int w = x2 - x1;
	int h = y2 - y1;

	//draw the top line
	for (int i = 0; i < w+1; i++) {
		gotoxy(x1 + i, y1);
		if (i == 0) {
			printf("%c", 218); // topleft corner
		} else if (i == w) {
			printf("%c", 191); // topright corner
		} else {
			printf("%c", 196); // horizontal line
		}
	}

	//draw the sides

	for (int i = 1; i < h; i++) {
			gotoxy(x1, y1 + i);
			printf("%c", 179);

			gotoxy(x2, y1 + i);
			printf("%c", 179);
			}

	//draw the bottom line
	for (int i = 0; i < w+1; i++) {
				gotoxy(x1 + i, y2);
				if (i == w) {
					printf("%c", 217); // bottomright corner
				} else if (i == 0) {
					printf("%c", 192); // bottomleft corner
				} else {
					printf("%c", 196); // horizontal line
				}
			}


}

