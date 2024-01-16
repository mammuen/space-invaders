/*
 * bullet.h
 *
 *  Created on: Jan 11, 2024
 *      Author: markus
 */

#ifndef BULLET_H_
#define BULLET_H_

#include <stdlib.h>
#include "game.h"
#include "ansi.h"
#include "player.h"


typedef struct {
	uint32_t x;
	uint32_t y;
	uint32_t Vx;
	uint32_t Vy;
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

extern char bulletPrint[3][3];




#endif /* BULLET_H_ */
