/*
 * enemies.c
 *
 *  Created on: Jan 10, 2024
 *      Author: markus
 */

#include "enemies.h"


Enemy* initEnemy(int diff) {
    Enemy* enemies = malloc(6 * sizeof(Enemy));


    if (enemies != NULL) {
        for (int i = 0; i < 6; i++) {
            enemies[i].health = 0;
            enemies[i].speed = 0;
            enemies[i].type = 0;
            enemies[i].x = 0;
            enemies[i].y = 0;
        }


    switch(diff){
    default:
    case 3:

        for (int i = 0; i < 6; i++) {
            enemies[i].health = 2;
            enemies[i].speed = 1;
            enemies[i].type = 1;
            enemies[i].x = 170;
            enemies[i].y = i * 8 + 5;
        }
    break;

    case 2:

        for (int i = 0; i < 4; i++) {
            enemies[i].health = 2;
            enemies[i].speed = 1;
            enemies[i].type = 1;
            enemies[i].x = 170;
            enemies[i].y = i * 10 + 5;
        }
    break;

    case 1:

        for (int i = 0; i < 2; i++) {
            enemies[i].health = 2;
            enemies[i].speed = 1;
            enemies[i].type = 1;
            enemies[i].x = 170;
            enemies[i].y = i* 20 + 5;
        }
    break;

    }



    }

    return enemies;
}

void spawnEnemies(Enemy* enemies){

	for(int i = 0; i < 6; i++){
		enemies[i].health = 4;
		enemies[i].speed = 1;
		enemies[i].type = 1;
		enemies[i].x = 170;
		enemies[i].y = i*8 + 5;
	}




}



void drawEnemies(Enemy* enemies){

	for(int i = 0; i < 6; i++){
		if(enemies[i].health > 0){
			printEnemy(enemies[i].x,enemies[i].y);
		}
	}
}

void printEnemy(int x,int y){
	int heigth = 4;
	int width  = 3;


	for(int i = 0; i < heigth; i++){
		for(int j = 0; j < width; j++){
			gotoxy(x+i,y+j);
			printf("%c",enemyPrint[j][i]);

	}

}
}


int updateEnemies(Enemy* enemies, Player* p1){


	for(int i = 0; i < 6; i++){
		if(enemies[i].x < 10){
			enemies[i].health = 0;
			p1->health -=1;


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

	if(enemies[0].health < 1 &&
		enemies[1].health < 1 &&
		enemies[2].health < 1 &&
		enemies[3].health < 1 &&
		enemies[4].health < 1 &&
		enemies[5].health < 1){

		spawnEnemies(enemies);


		return 1;
	}

	return 0;
}


char enemyPrint[3][4] =  {
		{' ',' ',',', ' '},
		{'<','@','#', ' '},
		{' ',' ','\'', ' '}
};

