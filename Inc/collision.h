/*
 * collision.h
 *
 *  Created on: Jan 9, 2024
 *      Author: markus
 */

#ifndef COLLISION_H_
#define COLLISION_H_

#include "game.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <enemies.h>
#include <bullet.h>
#include "asteroid.h"



int BulletEnemycollision(Enemy* E, Bullet* B);
int EnemyPlayercollision(Enemy* E, Player* P);
int EnemyAsteroidcollision(Enemy* E,Asteroid* Asteroid);
int BulletAsteroidcollision(Bullet* B,Asteroid* A);





#endif /* COLLISION_H_ */
