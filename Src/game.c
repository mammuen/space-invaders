#include "ansi.h"
#include <stdio.h>
#include <string.h>
#include "game.h"
#include <stdlib.h>



enemy* initEnemy() {
    enemy* enemies = malloc(6 * sizeof(enemy));

    if (enemies != NULL) {
        for (int i = 0; i < 6; i++) {
            enemies[i].health = 1;
            enemies[i].speed = 1;
            enemies[i].type = 1;
            enemies[i].x = 170;
            enemies[i].y = i * 8;
        }
        enemies[3].speed = 3;
    }

    return enemies;
}

void spawnEnemies(enemy* enemies){

	for(int i = 0; i < 6; i++){
		enemies[i].health = 1;
		enemies[i].speed = 1;
		enemies[i].type = 1;
		enemies[i].x = 170;
		enemies[i].y = i*8;
	}
		enemies[3].speed = 3;
}



void drawEnemies(enemy* enemies){

	for(int i = 0; i < 6; i++){
		if(enemies[i].health > 0){
			gotoxy(enemies[i].x,enemies[i].y);
			printf("< :( ==<");
		}
	}
}


int updateEnemies(enemy* enemies){


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

	if(enemies[0].health == 0 &&
		enemies[1].health == 0 &&
		enemies[2].health == 0 &&
		enemies[3].health == 0 &&
		enemies[4].health == 0 &&
		enemies[5].health == 0){
		return 1;
	}

	return 0;
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

void drawPlayer(int x, int y) {
	gotoxy(x, y);
	printf("%c%c%c%c", 61, 95, 95, 92);
	gotoxy(x, y+1);
	printf("  %co o%c%c%c%c", 124, 41, 61, 45, 45);
	gotoxy(x, y+2);
	printf("%c%c%c%c", 61, 45, 45, 47);
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
