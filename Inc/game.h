/*
 * game.h
 *
 *  Created on: 8 Jan 2024
 *      Author: oscar
 */

#ifndef GAME_H_
#define GAME_H_

typedef struct {
	int x;
	int y;
	int powerup;
	int display;
} bullet;

typedef struct {
	int x;
	int y;
	int health;
	int score;
	int bullets;
	int powerup;
} player;

typedef struct{
	int x;
	int y;
	int size;
	int health;
} asteriod;

typedef struct{
	int x;
	int y;
	int type;
	int speed;
	int health;
} enemy;



void initPlayer(player p);
void initAsteroid();
bullet* initBullet();
enemy* initEnemy();

void drawPlayer();
void drawAsteroid();
void drawBullet();
void drawEnemies(enemy*);


void updateEnemies(enemy*);




void drawGameDisplay();
void showCursor();
void hideCursor();
void updatePlayer();
void getKeystrokes();
void drawAsteroid();
void updateAsteroid();

#endif /* GAME_H_ */
