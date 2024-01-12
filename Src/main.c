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
    //int Player = {5, 10, 1, 1, 1, 1};
    Player p1;
    p1.x = 10;
    p1.y = 2;
    p1.bullets = 5;

    Window window = {width, height}; // creates a window struct
    char input;

    clrscr();
	drawGameDisplay(window);


	while (1) {

		drawPlayer(&p1);
		drawBullets(B);
		input = keyboardinput();

		if(input == 10){
			spawn1Bullet(B,&p1);
			bulletamount(LCD, p1.bullets+1);
		}

		if(input == 3){p1.y++;}
		if(input == 1){p1.y--;}
		if(p%10 == 1){
			BulletEnemycollision(E,B);
			updateBullets(B);
		}

		if(p%100 == 1){
		    clrscr();
			updateEnemies(E);
			drawEnemies(E);
		}

		p++;

	}

}

