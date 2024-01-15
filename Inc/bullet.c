/*
 * bullet.c
 *
 *  Created on: Jan 11, 2024
 *      Author: markus
 */

#include "bullet.h"


Bullet* initBullets() {
    Bullet* bullets = (Bullet*) malloc(6 * sizeof(Bullet));

    if (bullets != NULL) {
        for (int i = 0; i < 6; i++) {
        	bullets[i].health = 0;
        	bullets[i].type = 1;
        	bullets[i].powerup = 1;
        	bullets[i].x = 0;
        	bullets[i].y = 0;
        }
    }
    return bullets;
}




void spawn1Bullet(Bullet* bullets, Player* p){

	//for(int i = 0; i < 6; i++){
	//}
	if(p->bullets >= 0){
	bullets[ p->bullets ].health = 1;
	bullets[ p->bullets ].x = p->x+10;
	bullets[ p->bullets ].y = p->y+2;
	bullets[ p->bullets ].powerup = p->powerup + 1;
	p->bullets--;
	}
	else {
		reload(bullets, p);
	}

}





void drawBullets(Bullet* bullets){

	for(int i = 0; i < 6; i++){
		if(bullets[i].health > 0){
			printBullet(bullets[i].x,bullets[i].y);
		}
	}
}



void printBullet(int x,int y){
	gotoxy(x,y);
	int width  = 3;

		for(int j = 0; j < width; j++){
			gotoxy(x+j,y);
			printf("%c",bulletPrint[j]);
	}
}



int updateBullets(Bullet* bullets){


	for(int i = 0; i < 6; i++){
		if(bullets[i].x > 160){
			bullets[i].health = 0;
		}
	}


	for(int i = 0; i < 6; i++){
		if(bullets[i].health < 1){
			bullets[i].x = 180;
			bullets[i].y = 0;
		}
	}


	for(int i = 0; i < 6; i++){
		bullets[i].x = bullets[i].x + 1;

	}

	if(		bullets[0].health == 0 &&
			bullets[1].health == 0 &&
			bullets[2].health == 0 &&
			bullets[3].health == 0 &&
			bullets[4].health == 0 &&
			bullets[5].health == 0){
		return 1;
	}
	return 0;
}


void reload(Bullet* B, Player* P){

	//some kind of wait function
	P->bullets = 5;
	for(int i = 0; i < 6; i++){
		B[i].health = 0;
	}
}





char bulletPrint[3] = {' ','=','>'};
