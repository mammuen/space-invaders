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


			}
		}
	}
	}
}
	return 0;

}














//= {
//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//}
