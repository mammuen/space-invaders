/*
 * collision.c
 *
 *  Created on: Jan 9, 2024
 *      Author: markus
 */

#include "collision.h"



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


int EnemyAsteroidcollision(Enemy* E,Asteriod* A){


	int diff = 2;

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			if(A[i].health > 0){

 			if( abs(A[i].x - E[j].x - A[i].size/2) < diff ){
				if( abs(A[i].y - E[j].y - A[i].size/2) < diff ){

					A[i].health = 0;
					return 1;

			}
		}
	}
	}
}

	return 0;
}



int BulletAsteroidcollision(Bullet* B,Asteriod* A){

	int diff = 10;

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			if(A[i].health > 0){
			if(B[i].health > 0){


 			if( abs(A[i].x - B[j].x ) < diff ){
				if( abs(A[i].y - B[j].y ) < diff ){

					B[i].health = 0;
					return 1;

				}
 			}
		}
	}
}
}
	return 0;
}





