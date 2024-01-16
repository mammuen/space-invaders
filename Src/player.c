/*
 * player.c
 *
 *  Created on: 12 Jan 2024
 *      Author: oscar
 */

#include "player.h"
#include "ansi.h"
#include <stdio.h>


void playerinit(Player* p1){
	p1->health = 3;
	p1->x = 10 ;
	p1->y = 10;
	p1->score = 0;
	p1->powerup = 0;
	p1->bullets = 6;


}



void drawPlayer(Player p) {
	int x = p.x;
	int y = p.y;

	char graphics[5][13] =  {
			{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{'=', '_', '_', '\\', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ', ' ', ' ', '|', ' ', 'o', ' ', 'o', ')', '=', '-', '-', ' '},
			{'=', '-', '-', '/', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
			{' ' , ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
	};

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 13; j++) {
			gotoxy(x+j, y+i);
			printf("%c", graphics[i][j]);
		}
	}
}

void updatePlayer(Player *p, char input, int w, int h) {
	// one input only
	/*
	if(input == 3){p->y++;}
	if(input == 1){p->y--;}
	if(input == 2){p->x--;}
	if(input == 4){p->x++;}
*/

	if(input &(0x10)){p->y++;}
	if(input &(0x20)){p->y--;}
	if(input &(0x40)){p->x--;}
	if(input &(0x80)){p->x++;}





	if (p->y >= h - 5) {p->y = h - 5;}
	if (p->y <= 2) {p->y = 2;}
	if (p->x+12 >= w) {p->x = w-12;}
	if (p->x <= 2) {p->x = 2;}
}
