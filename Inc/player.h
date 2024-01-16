/*
 * player.h
 *
 *  Created on: 12 Jan 2024
 *      Author: oscar
 */

#ifndef PLAYER_H_
#define PLAYER_H_

typedef struct {
	int x;
	int y;
	int health;
	int score;
	int bullets;
	int powerup;
} Player;

extern char grahpics;


void playerinit(Player* p1);
void drawPlayer(Player p);
void updatePlayer(Player *p, char input, int w, int h);

#endif /* PLAYER_H_ */
