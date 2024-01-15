#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ansi.h"
#include "game.h"
#include "keyboard.h"



Powerup* initPowerup(){
	Powerup* P = (Powerup*) malloc(sizeof(Powerup));
	P->health = 0;
	P->x      = 0;
	P->y      = 0;

	return P;

}


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

void drawStars(){
	// TODO: finish background graphics
	gotoxy(19, 5);
	printf("*");
	gotoxy(15, 39);
	printf("*");
	gotoxy(26, 40);
	printf("*");
	gotoxy(21, 30);
	printf("*");
	gotoxy(19, 20);
	printf("*");
	gotoxy(15, 10);
	printf("*");
	gotoxy(22, 41);
	printf("*");
	gotoxy(27, 9);
	printf("*");
	gotoxy(33, 33);
	printf("*");
	gotoxy(40, 13);
	printf("*");
	gotoxy(44, 17);
	printf("*");
	gotoxy(49, 21);
	printf("*");
	gotoxy(54, 28);
	printf("*");
	gotoxy(58, 36);
	printf("*");
	gotoxy(64, 31);
	printf("*");
	gotoxy(70, 24);
	printf("*");
	gotoxy(76, 16);
	printf("*");
	gotoxy(80, 11);
	printf("*");
	gotoxy(83, 8);
	printf("*");
	gotoxy(90, 36);
	printf("*");
	gotoxy(103, 17);
	printf("*");
	gotoxy(108, 29);
	printf("*");
	gotoxy(113, 22);
	printf("*");
	gotoxy(118, 10);
	printf("*");
	gotoxy(123, 5);
	printf("*");
	gotoxy(130, 32);
	printf("*");
	gotoxy(137, 16);
	printf("*");
	gotoxy(143, 13);
	printf("*");
	gotoxy(149, 41);
	printf("*");
	gotoxy(130, 35);
	printf("*");
	gotoxy(134, 38);
	printf("*");
	gotoxy(120, 37);
	printf("*");
	gotoxy(124, 43);
	printf("*");
	gotoxy(119, 38);
	printf("*");
	gotoxy(144, 32);
	printf("*");
}

void bosskey() {
	clrscr();
	gotoxy(2, 2);
	printf("** Work Stuff **");
	while (1) {
		char input = keyboardinput();
		char input2 = readjoystick();

		if (input == 'p' || input2 == 0x02) {
			break;
		}
	}
}







