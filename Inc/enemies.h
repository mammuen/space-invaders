/*
 * enemies.h
 *
 *  Created on: Jan 10, 2024
 *      Author: markus
 */

#ifndef ENEMIES_H_
#define ENEMIES_H_


#include "stdlib.h"
#include "stdio.h"
#include "ansi.h"
#include "player.h"

typedef struct{
	int x;
	int y;
	int type;
	int speed;
	int health;
} Enemy;

extern char enemyPrint[3][4];

Enemy* initEnemy(int diff);
void drawEnemies(Enemy*);
void spawnEnemies(Enemy*);

int updateEnemies(Enemy*,Player* p1);
void printEnemy(int x,int y);

#endif /* ENEMIES_H_ */
