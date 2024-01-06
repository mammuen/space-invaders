/*
 * ansi.h
 *
 *  Created on: 5 Jan 2024
 *      Author: oscar
 */

#ifndef ANSI_H_
#define ANSI_H_

#include <stdint.h>
#include <stdio.h>

typedef struct {
	int x;
	int y;
} Point;


void fgcolor(uint8_t foreground);
void bgcolor(uint8_t foreground);
void color(uint8_t foreground,uint8_t background);
void resetbgcolor();
void clrscr();
void clreol();
void gotoxy(uint8_t x, uint8_t y);
void underline(uint8_t on);
void blink(uint8_t on);
void inverse(uint8_t on);
void window(uint8_t x1 , uint8_t y1, uint8_t x2, uint8_t y2);
void window2(uint8_t x1 , uint8_t y1, uint8_t x2, uint8_t y2);
void drawAsciiWindow(Point *point1, Point *point2, int style);




#endif /* ANSI_H_ */
