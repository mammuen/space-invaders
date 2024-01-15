/*
 * enemies.c
 *
 *  Created on: Jan 10, 2024
 *      Author: markus
 */

#include "enemies.h"


Enemy* initEnemy() {
    Enemy* enemies = malloc(6 * sizeof(Enemy));

    if (enemies != NULL) {
        for (int i = 0; i < 6; i++) {
            enemies[i].health = 2;
            enemies[i].speed = 1;
            enemies[i].type = 1;
            enemies[i].x = 170;
            enemies[i].y = i * 8 + 5;
        }



    }

    return enemies;
}

void spawnEnemies(Enemy* enemies){

	for(int i = 0; i < 6; i++){
		enemies[i].health = 2;
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

