/*
 * game.h
 *
 *  Created on: 8 Jan 2024
 *      Author: oscar
 */

#ifndef GAME_H_
#define GAME_H_


typedef struct {
	int w;
	int h;
} Window;

typedef struct {
	int x;
	int y;
	int health;
} Powerup;


Powerup* initPowerup();
void drawGameDisplay(Window win);
void showCursor();
void hideCursor();
void drawStars();
void bosskey();

#endif /* GAME_H_ */
