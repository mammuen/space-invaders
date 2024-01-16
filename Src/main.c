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
#include "speaker.h"


int counter = 0;


void TIM1_BRK_TIM15_IRQHandler(void){
	TIM15->SR &= ~(0x0001);
	counter++;
}





int main() {




    //setup
    uart_init(600000);
	timerInit();
    joystickinit();
    speakerSetup();
    Player p1 = {5, 10, 3, 0, 0, 0};
    // x , y, health ,
    //score, bullets, powerup

    setup();
    ledsetup();


    hideCursor();
    clrscr();

    void onRed(int in);
    void onGreen(int in);
    void onBlue(int in);

    uint8_t count = 3;


    //variables
    int width = 200;
    int height = 50;




    int difficulty;

    Window window = {width, height}; // creates a window struct
    char input;
    char input2;

    clrscr();
	drawGameDisplay(window);
	int speed = 4;


	uint8_t* LCD = initalize_LCD();

    clrscr();

	while(1) {








	if(p1.health < 2){
		printf("GAME OVER");
		int i = 1000000;

		setFreq(300);
		while(i){
			i--;
		}
		i = 1000000;
		setFreq(150);
		while(i){
		i--;
		}
		i = 1000000;
		setFreq(75);
		while(i){
		i--;
		}
		setFreq(0);


		difficulty = endScreen(window,p1);



	} else {

	switch(selectMenu(window)){
		case 1:
			difficulty = 1;
			break;
		case 2:
			difficulty = 2;
			break;
		case 3:
			difficulty = 3;
			break;
		default:
			difficulty = 3;
		break;
	}
	}


	playerinit(&p1);

	//start enemies
	Enemy*  E = initEnemy(difficulty);
	Bullet* B = initBullets();
	Asteroid* A = initAsteroid(count);
	Powerup* P = initPowerup();

	while (p1.health > 0) {

		// update game object
		if(counter%2 == 0){
		updatePlayer(&p1, input2, window.w, window.h);
		gravity(A,B);
		}
		updateBullets(B);

		if(p1.powerup){
			stringAdd(LCD, "POWERUP ACTIVATED",0,2);
		} else {
			LCDclrline(LCD,2);
		}

		if(counter % 100 == 0){
			clrscr();
			drawGameDisplay(window);
			updateAsteroid(A, count);
			drawAsteroid(A, count);

		}

		if(counter%(128/speed) == 0){
		    healthamount(LCD,p1.health);
		    healthLED(p1.health);

		    if(updateEnemies(E,&p1)){
		    	speed = speed +1;
		    }

		}





		// draw game objects
		drawPlayer(p1);
		drawBullets(B);
		spawnpowerup(P);
		drawEnemies(E);






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
			p1.score = p1.score + 10 * (p1.powerup + 1);
			setScore(LCD,p1.score);
		}
		EnemyPlayercollision(E,&p1);
		PlayerAsteroidPowerupCollision(&p1,A,P);


		}
	}

}

