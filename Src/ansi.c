/*
 * ansi.c
 *
 *  Created on: 5 Jan 2024
 *      Author: oscar
 */

#define ESC 0x1B
#include "ansi.h"





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
	printf("%c[H", ESC);
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

void window(uint8_t x1 , uint8_t y1, uint8_t x2, uint8_t y2){

	int i;
	uint8_t width = x2-x1;
	uint8_t heigth= y2-y1;

	gotoxy(x1,y1);
	printf("%c", 218);
	printf("%c", 180);

	color(15,4);
	char text[12] = "window name";

	for(i = 0; i < 12; i++){
		printf("%c", text[i]);
	}

	for(i = 11; i < width-2; i++){
		printf("%c", 32);

	}
	color(15,0);

	printf("%c", 195);
	printf("%c", 191);


	for(i = 1; i < heigth; i++){
	gotoxy(x1,y1+i);
	printf("%c", 179);
	}

	for(i = 1; i < heigth; i++){
	gotoxy(x2+1,y1+i);
	printf("%c", 179);
	}

	gotoxy(x1,y2);
	printf("%c", 192);
	for(i = 0; i < width; i++){
		printf("%c", 196);

	}
	printf("%c", 217);

}

void window2(uint8_t x1 , uint8_t y1, uint8_t x2, uint8_t y2){

	int i;
	uint8_t width = x2-x1;
	uint8_t heigth= y2-y1;

	gotoxy(x1,y1);
	printf("%c", 218);
	printf("%c", 180);

	char text[12] = "window name";


	inverse(1);
	for(i = 0; i < 12; i++){
		printf("%c", text[i]);
	}
	inverse(0);

	printf("%c", 195);


	for(i = 11; i < width-2; i++){
		printf("%c", 196);

	}

	printf("%c", 191);


	for(i = 1; i < heigth; i++){
	gotoxy(x1,y1+i);
	printf("%c", 179);
	}

	for(i = 1; i < heigth; i++){
	gotoxy(x2+1,y1+i);
	printf("%c", 179);
	}

	gotoxy(x1,y2);
	printf("%c", 192);
	for(i = 0; i < width; i++){
		printf("%c", 196);

	}
	printf("%c", 217);

}




