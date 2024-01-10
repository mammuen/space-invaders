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
} Bullet;

typedef struct {
	int x;
	int y;
	int health;
	int score;
	int bullets;
	int powerup;
} Player;

typedef struct{
	int x;
	int y;
	int size;
	int health;
} Asteriod;

typedef struct{
	int x;
	int y;
	int type;
	int speed;
	int health;
} Enemy;

typedef struct {
	int w;
	int h;
} Window;



void initPlayer(Player p);
void initAsteroid();
Bullet* initBullet();
Enemy* initEnemy();

void drawPlayer();
void drawAsteroid();
void drawBullet();
void drawEnemies(Enemy*);


int updateEnemies(Enemy*);


void drawGameDisplay(Window win);
void showCursor();
void hideCursor();
void updatePlayer();
void getKeystrokes();
void drawAsteroid();
void updateAsteroid();

#endif /* GAME_H_ */
