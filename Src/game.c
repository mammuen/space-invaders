#include "ansi.h"
#include <stdio.h>
#include <string.h>
#include "game.h"
#include <stdlib.h>



Enemy* initEnemy() {
    Enemy* enemies = malloc(6 * sizeof(Enemy));

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

void spawnEnemies(Enemy* enemies){

	for(int i = 0; i < 6; i++){
		enemies[i].health = 1;
		enemies[i].speed = 1;
		enemies[i].type = 1;
		enemies[i].x = 170;
		enemies[i].y = i*8;
	}
		enemies[3].speed = 3;
}



void drawEnemies(Enemy* enemies){

	for(int i = 0; i < 6; i++){
		if(enemies[i].health > 0){
			printEnemy(enemies[i].x,enemies[i].y);
		}
	}
}

void printEnemy(int x,int y){
	gotoxy(x,y);
	int heigth = 3;
	int width  = 3;


	for(int i = 0; i < heigth; i++){
		for(int j = 0; j < width; j++){
			gotoxy(x+i,y+j);
			printf("%c",enemyPrint[j][i]);

	}

}
}


int updateEnemies(Enemy* enemies){


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

void drawPlayer(Player *p) {
	int x = p->x;
	int y = p->y;

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

void drawStars() {

}

char enemyPrint[3][3] =  {
		{' ',' ','|'},
		{'<','=','|'},
		{' ',' ','|'}
};





