/*
 * player.c
 *
 *  Created on: 12 Jan 2024
 *      Author: oscar
 */

#include "player.h"
#include "ansi.h"
#include <stdio.h>

void drawPlayer(Player p) {
	int x = p.x;
	int y = p.y;

	char graphics[5][12] =  {
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{'=', '_', '_', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', 'o', ' ', 'o', ')', '=', '-', '-'},
			{'=', '-', '-', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
	};

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 12; j++) {
			gotoxy(x+j, y+i);
			printf("%c", graphics[i][j]);
		}
	}
}

void updatePlayer(Player *p, char input, int h) {
	if(input == 3){p->y++;}
	if(input == 1){p->y--;}

	if (p->y >= h - 5) {p->y = h - 5;}
	if (p->y <= 2) {p->y = 2;}
}
