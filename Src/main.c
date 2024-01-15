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
#include "asteroid.h"
#include "joystick.h"
#include "timer.h"


int counter = 0;


void TIM1_BRK_TIM15_IRQHandler(void){
	TIM15->SR &= ~(0x0001);
	counter++;

}




int main() {



    //setup
    uart_init(460800);
	timerInit();

    joystickinit();
    hideCursor();
    clrscr();

    uint8_t count = 3;

    //start enemies
    Enemy*  E = initEnemy();
    Bullet* B = initBullets();
    uint8_t* LCD = initalize_LCD();
    Asteroid* A = initAsteroid(count);
    Powerup* P = initPowerup();

    //variables
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
    char input2;

    clrscr();
	drawGameDisplay(window);
	int speed = 50;



	while (1) {

		// update game object
		if(counter%2 == 0){
		updatePlayer(&p1, input2, window.w, window.h);
		}
		updateBullets(B);

		if(counter % 100 == 0){
			clrscr();
			updateAsteroid(A, count);
			drawAsteroid(A, count);

		}

		if(counter%speed == 0){
		    healthamount(LCD,p1.health);

		    if(updateEnemies(E)){
		    	speed = speed - 5;
		    }

			drawEnemies(E);
		}





		// draw game objects
		drawPlayer(p1);
		drawBullets(B);
		spawnpowerup(P);





		//input


		input = keyboardinput();
		input2 = readjoystick();

		if(input2&(0x01)){
			spawn1Bullet(B,&p1);
			bulletamount(LCD, p1.bullets+1);
		}

		if (input2 == 0x02 || input == 'p') {
					bosskey();
		}




		//collision detection
		EnemyAsteroidcollision(E,A);
		BulletAsteroidcollision(B,A,P);

		if(BulletEnemycollision(E,B)){
			p1.score = p1.score + 10;
			setScore(LCD,p1.score);
		}
		EnemyPlayercollision(E,&p1);
		PlayerAsteroidPowerupCollision(&p1,A,P);


		}
	}
