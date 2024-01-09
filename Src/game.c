/*
 * game.c
 *
 *  Created on: 8 Jan 2024
 *      Author: oscar
 */

#include "ansi.h"
#include <stdio.h>
#include <string.h>
#include "game.h"












enemy* initEnemy(){

	enemy* enemies = malloc(6*sizeof(enemy));

	for(int i = 0; i < 6; i++){
		enemies[i].health = 1;
		enemies[i].speed = 1;
		enemies[i].type = 1;
		enemies[i].x = 170;
		enemies[i].y = i*8;
	}
		enemies[3].speed = 3;
	return enemies;
}

void drawEnemies(enemy* enemies){

	for(int i = 0; i < 6; i++){
		if(enemies[i].health > 0){
		gotoxy(enemies[i].x,enemies[i].y);
		printf("< :( ==<");
		}
	}
}



void updateEnemies(enemy* enemies){


	for(int i = 0; i < 6; i++){
		if(enemies[i].x < 10){
		enemies[i].health = 0;
		}
	}


	for(int i = 0; i < 6; i++){
		if(enemies[i].health < 1){
		enemies[i].speed = 0;
		enemies[i].x = 180;
		}
	}


	for(int i = 0; i < 6; i++){
		enemies[i].x = enemies[i].x - enemies[i].speed;

	}

}





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
