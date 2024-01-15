/*
 * collision.c
 *
 *  Created on: Jan 9, 2024
 *      Author: markus
 */

#include "collision.h"

void spawnpowerup(int x, int y){

	gotoxy(x,y);
	printf("POW");


}



int BulletEnemycollision(Enemy* E, Bullet* B)
{

	int diff = 2;

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			if(B[i].health != 0){

 			if( abs(B[i].x - E[j].x+1) < diff ){
				if( abs(B[i].y - E[j].y - 1) < diff ){

					B[i].health = 0;
					E[j].health = 0;
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



int BulletAsteroidcollision(Bullet* B,Asteroid* A){

	int diff;

	int a;
	int b;
	int c;
	int d;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 6; j++){
			if(A[i].health > 0){
			if(B[j].health > 0){

				diff  = A[i].size;

				a = A[i].x + diff/2;
				b = B[j].x;

				c = A[i].y + diff/2;
				d = B[j].y;



 			if( abs(c - d) < diff){
				if( abs(a - b) < diff ){

					B[j].health = 0;
					A[i].health--;
					if(A[i].health == 0){
						spawnpowerup(A[i].x,A[i].y);
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


int PlayerAsteroidPowerupCollision(Player* B,Asteroid* A,Powerup* P){

	for(int i = 0; i < 3;i++){


	}

}






