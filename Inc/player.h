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

void drawPlayer(Player p);
void updatePlayer(Player *p, int speed);

#endif /* PLAYER_H_ */
