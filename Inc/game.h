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


void drawGameDisplay(Window win);
void showCursor();
void hideCursor();
void getKeystrokes();

#endif /* GAME_H_ */
