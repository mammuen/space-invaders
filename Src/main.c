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
    Player p1 = {5, 10, 1, 1, 5, 1};

    Window window = {width, height}; // creates a window struct
    char input;

    clrscr();
	drawGameDisplay(window);


	while (1) {

		// update game object
		updatePlayer(&p1, input, window.w, window.h);
		updateBullets(B);

		// draw game objects
		drawPlayer(p1);
		drawBullets(B);
		drawEnemies(E);

		input = keyboardinput();

		if(input == 10){
			spawn1Bullet(B,&p1);
			bulletamount(LCD, p1.bullets+1);
		}

		if (p % 10 == 0) {
			drawGameDisplay(window);
			BulletEnemycollision(E,B);

			updateEnemies(E);
		}

		if(p%40 == 0){
		    clrscr();
		}

		p++;

		if (p > 100000000) {
			p = 0;
		}

	}

}
