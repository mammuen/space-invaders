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
#include "LED.h"
#include "flash.h"

int counter = 0;

void TIM1_BRK_TIM15_IRQHandler(void){
	TIM15->SR &= ~(0x0001);
	counter++;
}

int main() {

	// vi tjekker om highscore værdien gemt er reset værdien i ubrugt memory
	// hvis det er så skriver at highscore skal være lig med 0
	if(flashreadadd(0) > 65530){
		writeflash(0,0);
	}


    uart_init(1000000); 
    // Initialiserer UART-kommunikationen med en baudrate på 1000000
    clrscr(); // Rydder terminalvinduet for tidligere output

    //setup
	timerInit(); // Initialiserer spiltimeren
    joystickinit();  // Initialiserer joystick-input
    speakerSetup(); // Opsætter højttaleren til spillyde
    Player p1 = {5, 10, 3, 0, 0, 0};
// Opretter Player med startposition, sundhed, score, antal kugler og power-up

    setup(); // Kører opsætningsfunktionen for Joystick
    ledsetup(); // Initialiserer LED-belysning.


    hideCursor(); // Skjuler tekstmarkøren/musen på skærmen.
    clrscr();

    // Deklarerer tre funktioner til styring af LED-lys.
    void onRed(int in);
    void onGreen(int in);
    void onBlue(int in);

    // Initialiserer en tæller med værdien 3 for antallet af asteroider.
    uint8_t count = 3;


    // Variabler til spilvinduet
    int width = 200;
    int height = 50;


    int difficulty;


    Window window = {width, height}; 
    // Opretter et vindueobjekt med specifikke dimensioner.
    char input;
    char input2;

    clrscr(); // Rydder skærmen igen og forbereder den til spillet.
	drawGameDisplay(window); // Tegner spilvinduet.
	int speed = 4;

	// Initialiserer et LCD-display.
	uint8_t* LCD = initalize_LCD();


	while(1) {

		// Hovedspilsløjfe

	if(p1.health < 2){
		printf("GAME OVER"); 
// Viser "GAME OVER" på skærmen på vores SMT32-board, når spilleren løber tør for sundhed.
		int i = 1000000;

		// Indstiller højttalerfrekvensen til 300 Hz.
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

		// Ændrer højttalerfrekvensen for lydeffekter.
		setFreq(0);


// Gemmer spillerens score i flash-hukommelsen,
// hvis den er højere end den tidligere gemte score.
		if(p1.score > flashreadadd(0)){
			writeflash(0,p1.score);
		}

		// Viser slutskærmen og opdaterer sværhedsgraden.
		difficulty = endScreen(window,p1,difficulty);

	} else {

	// Bruger en menu til at vælge sværhedsgraden, hvis spillet ikke er slut.
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

	// Initialiserer spilleren.
	playerinit(&p1);

	// Starter fjender, kugler, asteroider og power-ups
	// Initialiserer spilobjekterne og rydder skærmen.
	Enemy*  E = initEnemy(difficulty);
	Bullet* B = initBullets();
	Asteroid* A = initAsteroid(count);
	Powerup* P = initPowerup();
    clrscr();

	while (p1.health > 0) {

		// Spillet kører, så længe spilleren har sundhed tilbage

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

		// Opdaterer og tegner asteroider periodisk.

		if(counter % 100 == 0){
			clrscr();
			drawStars();
			drawGameDisplay(window);
			updateAsteroid(A, count);
			drawAsteroid(A, count);

		}

		// Opdaterer fjender, sundhedsdisplay

		if(counter%(128/speed) == 0){
		    healthamount(LCD,p1.health);
		    healthLED(p1.health);

		    if(updateEnemies(E,&p1, difficulty)){
		    	speed = speed +1;
		    }

		}


		// Tegn spilobjekter
		drawPlayer(p1);
		drawBullets(B);
		spawnpowerup(P);
		drawEnemies(E);


		// Input fra tastatur og joystick
		input = keyboardinput();
		input2 = readjoystick();


		// Håndterer input fra joystick og udløser skud.
		if(input2&(0x01)){
			spawn1Bullet(B,&p1);
			bulletamount(LCD, p1.bullets+1);
		}

		if (input2 == 0x02 || input == 'p') {
					bosskey();
		}


		// Kollisionstjek
		EnemyAsteroidcollision(E,A);
		BulletAsteroidcollision(B,A,P);

		// Tjekker kollisioner mellem spilobjekter.
		if(BulletEnemycollision(E,B)){
			p1.score = p1.score + 10 * (p1.powerup + 1);
			setScore(LCD,p1.score);
		}
		EnemyPlayercollision(E,&p1);
		PlayerAsteroidPowerupCollision(&p1,A,P);

		}
	}

}

