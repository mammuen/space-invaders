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


typedef struct {
	int w;
	int h;
} Window;



void initPlayer(Player p);
void initAsteroid();

void drawPlayer();
void drawAsteroid();



void drawGameDisplay(Window win);
void showCursor();
void hideCursor();
void updatePlayer();
void getKeystrokes();
void drawAsteroid();
void updateAsteroid();



#endif /* GAME_H_ */
