/*
 * bullet.c
 *
 *  Created on: Jan 11, 2024
 *      Author: markus
 */

#include "bullet.h"


Bullet* initBullets() {
    Bullet* bullets = (Bullet*) malloc(8 * sizeof(Bullet));

    if (bullets != NULL) {
        for (int i = 0; i < 8; i++) {
        	bullets[i].health = 0;
        	bullets[i].type = 1;
        	bullets[i].powerup = 1;
        	bullets[i].x = 0;
        	bullets[i].y = 0;
        	bullets[i].Vx = (1 << 16);
        	bullets[i].Vy = 0;
        }
    }
    return bullets;
}




void spawn1Bullet(Bullet* bullets, Player* p){

	//for(int i = 0; i < 6; i++){
	//}
	if(p->bullets >= 0){
	bullets[ p->bullets ].health = 1;
	bullets[ p->bullets ].x = (p->x+10) << 16;
	bullets[ p->bullets ].y = (p->y+2 ) << 16;
	bullets[ p->bullets ].powerup = p->powerup + 1;
	p->bullets--;
	}
	else {
		reload(bullets, p);
	}

}





void drawBullets(Bullet* bullets){

	for(int i = 0; i < 8; i++){
		if(bullets[i].health > 0){
			printBullet(
					(bullets[i].x >> 16),
					(bullets[i].y >> 16)
					);
		}
	}
}



void printBullet(int x,int y){
	gotoxy(x,y);
	int width  = 3;
	int heigth = 3;


		for(int j = 0; j < width; j++){
			for(int i = 0; i < heigth; i++){

			gotoxy(x+j,y);
			printf("%c",bulletPrint[j][i]);
			}
	}
}



int updateBullets(Bullet* bullets){


	for(int i = 0; i < 8; i++){
		if((bullets[i].x >> 16) > 180){
			bullets[i].health = 0;
		}
	}


	for(int i = 0; i < 8; i++){
		if(bullets[i].health < 1){
			bullets[i].x = 180 >> 16;
			bullets[i].y = 0;
		}
	}


	for(int i = 0; i < 8; i++){
		bullets[i].x = bullets[i].x + bullets[i].Vx;
		bullets[i].y = bullets[i].y + bullets[i].Vy;
	}

	if(		bullets[0].health == 0 &&
			bullets[1].health == 0 &&
			bullets[2].health == 0 &&
			bullets[3].health == 0 &&
			bullets[4].health == 0 &&
			bullets[5].health == 0 &&
			bullets[6].health == 0 &&
			bullets[7].health == 0){
		return 1;
	}
	return 0;
}


void reload(Bullet* B, Player* P){

	//some kind of wait function
	P->bullets = 8;
	P->powerup = 0;
	for(int i = 0; i < 8; i++){
		B[i].health = 0;
		B[i].Vy = 0;
	}
}





char bulletPrint[3][3] = {{' ',' ',' ',},{' ','=','>'},{' ',' ',' ',}};
