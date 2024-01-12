/*
 * collision.c
 *
 *  Created on: Jan 9, 2024
 *      Author: markus
 */

#include "collision.h"



int BulletEnemycollision(Enemy* E, Bullet* B)
{
	int diff = 4;

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			if( abs(B[i].x - E[i].x+1) < diff ){
				if( abs(B[i].y - E[i].y+2) < diff ){

					B[i].health = 0;
					E[i].health = 0;


			}
		}
	}
}
	return 0;

}














//= {
//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//}
