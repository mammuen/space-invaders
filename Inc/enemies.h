/*
 * enemies.h
 *
 *  Created on: Jan 10, 2024
 *      Author: markus
 */

#ifndef ENEMIES_H_
#define ENEMIES_H_


#include "stdlib.h"


typedef struct{
	int x;
	int y;
	int type;
	int speed;
	int health;
} Enemy;

extern char enemyPrint[3][3];



Enemy* initEnemy();
void drawEnemies(Enemy*);
int updateEnemies(Enemy*);
void printEnemy(int x,int y);




#endif /* ENEMIES_H_ */