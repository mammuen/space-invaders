/*
 * player.c
 *
 *  Created on: 12 Jan 2024
 *      Author: oscar
 */

#include "player.h"

void drawPlayer(Player p) {
	int x = p.x;
	int y = p.y;

	// print 1st line
	gotoxy(x, y);
	printf("%c", 61);
	gotoxy(x+1, y);
	printf("%c", 95);
	gotoxy(x+2, y);
	printf("%c", 95);
	gotoxy(x+3,y);
	printf("%c",92);

	// print second line
	gotoxy(x, y+1);
	printf(" ");
	gotoxy(x+1, y+1);
	printf(" ");
	gotoxy(x+2, y+1);
	printf("%c", 124);
	gotoxy(x+3, y+1);
	printf("o");
	gotoxy(x+4, y+1);
	printf(" ");
	gotoxy(x+5, y+1);
	printf("o");
	gotoxy(x+6, y+1);
	printf("%c", 41);
	gotoxy(x+7, y+1);
	printf("%c", 61);
	gotoxy(x+8, y+1);
	printf("%c", 45);
	gotoxy(x+9, y+1);
	printf("%c", 45);

	// print last line
	gotoxy(x, y+2);
	printf("%c", 61);
	gotoxy(x+1, y+2);
	printf("%c", 45);
	gotoxy(x+2, y+2);
	printf("%c", 45);
	gotoxy(x+3, y+2);
	printf("%c", 47);

}

void updatePlayer(Player *p, int speed) {
	p->y += speed;
}
