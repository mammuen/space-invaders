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
        	bullets[i].x = 0;
        	bullets[i].y = 0;
        }
    }
    return bullets;
}




void spawn1Bullet(Bullet* bullets, Player* p){

	//for(int i = 0; i < 6; i++){
	bullets[0].health = 1;
	bullets[0].x = p->x+3;
	bullets[0].y = p->y+1;

	//}
}





void drawbullets(Bullet* bullets){

	for(int i = 0; i < 6; i++){
		if(bullets[i].health > 0){
			printBullet(bullets[i].x,bullets[i].y);
		}
	}
}



void printBullet(int x,int y){
	gotoxy(x,y);
	int width  = 2;

		for(int j = 0; j < width; j++){
			gotoxy(x+j,y);
			printf("%c",bulletPrint[j]);
	}
}



int updatebullets(Bullet* bullets){


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





char bulletPrint[2] = {'=','>'};
