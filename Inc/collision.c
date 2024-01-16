/*
 * collision.c
 *
 *  Created on: Jan 9, 2024
 *      Author: markus
 */

#include "collision.h"

void spawnpowerup(Powerup* P){
if(P->health != 0){
	gotoxy(P->x,P->y);
	printf("POW-UP");
}
}



int BulletEnemycollision(Enemy* E, Bullet* B)
{

	int diff = 2;

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 6; j++){
			if(B[i].health != 0){

 			if( abs((B[i].x >> 16) - E[j].x+1) < diff ){
				if( abs((B[i].y >> 16) - E[j].y - 1) < diff ){

					B[i].health = 0;


					E[j].health = E[j].health - B[j].powerup;
					return 1;

			}
		}
	}
	}
}
	return 0;
}



int EnemyPlayercollision(Enemy* E, Player* P)
{

	int diff = 6;

		for(int j = 0; j < 6; j++){
			if(E[j].health != 0){

				if( abs(P->x + 4 - E[j].x + 1) < diff ){
				if( abs(P->y + 2 - E[j].y - 1) < diff ){

					P->health = P->health -1;
					P->x = 3;
					P->y = 5;

					//E[j].health = 0;
					return 1;

			}
		}
	}
}
	return 0;
}


int EnemyAsteroidcollision(Enemy* E,Asteroid* Asteroid){

	int a;
	int b;
	int c;
	int d;

	int diff = 5;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 6; j++){

			if(E[j].health > 0){
			if(Asteroid[i].health > 0){


			a = Asteroid[i].x + 3;
			b = E[j].x;

			c = Asteroid[i].y + 3;
			d = E[j].y;


			if( abs( a - b ) < diff ){

 			if( abs(c  - d ) < diff ){


 					Asteroid[i].health = 0;
					return 1;

			}
		}
		}
		}
	}
}

	return 0;
}



int BulletAsteroidcollision(Bullet* B,Asteroid* A, Powerup* P){

	int diff;

	int a;
	int b;
	int c;
	int d;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 8; j++){
			if(A[i].health > 0){
			if(B[j].health > 0){

				diff  = A[i].size;

				a = A[i].x + diff/2;
				b = B[j].x >> 16;

				c = A[i].y + diff/2;
				d = B[j].y >> 16;



 			if( abs(c - d) < diff){
				if( abs(a - b) < diff ){

					B[j].health = 0;
					A[i].health--;
					if(A[i].health == 0){

						P->health = 1;
						P->x = A[i].x;
						P->y = A[i].y;
					}
					return 1;

				}
 			}
		}
	}
}
}
	return 0;
}


int PlayerAsteroidPowerupCollision(Player* Pl,Asteroid* A,Powerup* P){

	for(int i = 0; i < 3;i++){
			if( abs(Pl->x - A[i].x  + A[i].size/2) < A[i].size ){
			if( abs(Pl->y - A[i].y  + A[i].size/2)< A[i].size ){
				Pl->health = Pl->health -1;
				Pl->x = 3;
				Pl->y = 5;
				return 1;

			}}
	}

	if( abs(Pl->x - P->x) < 5){
		if( abs(Pl->y - P->y) < 5){
			if(P->health != 0){

			Pl->powerup = 1;
			Pl->health--;

			P->health = 0;

		}}}

	return 0;
}

int gravity(Asteroid* A, Bullet* B){

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 3; j++){

			if(B[i].health > 0){


				if( abs(A[j].x + A[j].size/2 - (B[i].x >> 16)) < 4 ){

					B[i].Vy = 1000/(A[j].y - (B[i].y >> 16)) << 6;

				}



			}
		}
	}


}







