/*
 * game.h
 *
 *  Created on: 8 Jan 2024
 *      Author: oscar
 */

#ifndef GAME_H_
#define GAME_H_

typedef struct{
	int x;
	int y;
	int size;
	int health;
} Asteriod;

typedef struct {
	int w;
	int h;
} Window;

void initAsteroid();
void drawAsteroid();
void drawAsteroid();
void updateAsteroid();

void drawGameDisplay(Window win);
void showCursor();
void hideCursor();
void getKeystrokes();

#endif /* GAME_H_ */
