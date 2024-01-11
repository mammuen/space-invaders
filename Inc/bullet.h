/*
 * bullet.h
 *
 *  Created on: Jan 11, 2024
 *      Author: markus
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "game.h"
#include <stdlib.h>
#include "ansi.h"


typedef struct {
	int x;
	int y;
	int health;
	int type;
	int powerup;
	int display;
} Bullet;



Bullet* initBullets();
void spawn1Bullet(Bullet* bullets, Player* p);

void drawBullets();
void printBullet(int x,int y);
int updateBullets(Bullet* bullets);
void reload(Bullet* B, Player* P);

extern char bulletPrint[3];




#endif /* BULLET_H_ */
