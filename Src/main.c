#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "ansi.h"
#include "charset.h"
#include "game.h"
#include "menu.h"
#include "LCDdisplay.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <enemies.h>
#include <bullet.h>
#include <keyboard.h>
#include <collision.h>



int main() {

    //setup
    uart_init(460800);

    hideCursor();
    clrscr();

    //start enemies
    Enemy*  E = initEnemy();
    Bullet* B = initBullets();
    uint8_t* LCD = initalize_LCD();

    //variables
    int p = 0;
    int width = 200;
    int height = 50;
    Player p1 = {5, 10, 3, 0, 6, 0};
    // x , y, health ,
    //score, bullets, powerup


    /*

    Player p1;
    p1.x = 10;
    p1.y = 2;
    p1.bullets = 5;

    */

    Window window = {width, height}; // creates a window struct
    char input;

    clrscr();
	drawGameDisplay(window);


	while (1) {

		drawPlayer(p1);
		drawBullets(B);
		input = keyboardinput();

		if(input == 10){

			spawn1Bullet(B,&p1);
			bulletamount(LCD, p1.bullets+1);
		}

		if(p % 20 == 0){

			updateEnemies(E);
			drawEnemies(E);
		}




		if(input == 3){p1.y++;}
		if(input == 1){p1.y--;}

		if(BulletEnemycollision(E,B)){
			p1.score = p1.score + 10;
			setScore(LCD,p1.score);
		}
		EnemyPlayercollision(E,&p1);
		updateBullets(B);

		if(p%50 == 1){
		    clrscr();
		}



		p++;

	}

}
