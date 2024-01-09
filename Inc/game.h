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



void initPlayer();
void initAsteroid();
void initbullet();
void initenemy();






void drawGameDisplay();
void showCursor();
void hideCursor();
void drawPlayer();
void updatePlayer();
void getKeystrokes();
void drawAsteroid();
void updateAsteroid();

#endif /* GAME_H_ */
