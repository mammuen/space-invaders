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

void drawBullet();
void printBullet(int x,int y);
int updateBullets(Bullet* bullets);

extern char bulletPrint[2];




#endif /* BULLET_H_ */
