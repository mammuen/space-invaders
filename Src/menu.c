/*
 * menu.c
 *
 *  Created on: 8. jan. 2024
 *      Author: doube
 */

#include "menu.h"
#include "game.h"

void delay(uint32_t count) {
    while (count--) {
    }
}

void drawMenu(int selectedItem) {
	    gotoxy(10, 10);
	    printf(" ________  ________  ________  ________  _______           ________  ________  ___      ___ _______   ________   _________  ___  ___  ________  _______      ");
	    gotoxy(10, 11);
	    printf(" |\\   ____\\|\\   __  \\|\\   __  \\|\\   ____\\|\\  ___ \\         |\\   __  \\|\\   ___ \\|\\  \\    /  /|\\  ___ \\ |\\   ___  \\|\\___   ___\\\\  \\|\\  \\|\\   __  \\|\\  ___ \\     ");
	    gotoxy(10, 12);
	    printf(" \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\___|\\ \\   __/|        \\ \\  \\|\\  \\ \\  \\_|\\ \\ \\  \\  /  / | \\   __/|\\ \\  \\\\ \\  \\|___ \\  \\_\\ \\  \\\\\\  \\ \\  \\|\\  \\ \\   __/|    ");
	    gotoxy(10, 13);
	    printf("  \\ \\_____  \\ \\   ____\\ \\   __  \\ \\  \\    \\ \\  \\_|/__       \\ \\   __  \\ \\  \\ \\\\ \\ \\  \\/  / / \\ \\  \\_|/_\\ \\  \\\\ \\  \\   \\ \\  \\ \\ \\  \\\\\\  \\ \\   _  _\\ \\  \\_|/__  ");
	    gotoxy(10, 14);
	    printf("   \\|____|\\  \\ \\  \\___|\\ \\  \\ \\  \\ \\  \\____\\ \\  \\_|\\ \\       \\ \\  \\ \\  \\ \\  \\_\\\\ \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\ \\  \\   \\ \\  \\ \\ \\  \\\\\\  \\ \\  \\\\  \\\\ \\  \\_|\\ \\ ");
	    gotoxy(10, 15);
	    printf("     ____\\_\\  \\ \\__\\    \\ \\__\\ \\__\\ \\_______\\ \\_______\\       \\ \\__\\ \\__\\ \\_______\\ \\__/ /     \\ \\_______\\ \\__\\\\ \\__\\   \\ \\__\\ \\ \\_______\\ \\__\\\\ _\\\\ \\_______\\");
	    gotoxy(10, 16);
	    printf("    |\\_________\\|__|     \\|__|\\|__|\\|_______|\\|_______|        \\|__|\\|__|\\|_______|\\|__|/       \\|_______|\\|__| \\|__|    \\|__|  \\|_______|\\|__|\\|__|\\|_______|");
	    gotoxy(10, 17);
	    printf("    \\|_________|                                                                                                                                              ");


    if (selectedItem == 1) {
    	gotoxy(80,25);
        printf("      ___  _    ____ _   _ ");
        gotoxy(80,26);
        printf("__    |__] |    |__|  \\_/  ");
        gotoxy(80,27);
        printf("      |    |___ |  |   |   ");

        gotoxy(80,28);
        printf("      _  _ ____ _    ___  ");
        gotoxy(80,29);
        printf("      |__| |___ |    |__] ");
        gotoxy(80,30);
        printf("      |  | |___ |___ |    ");

    } else {
        gotoxy(80, 25);
        printf("      ___  _    ____ _   _ ");
        gotoxy(80, 26);
        printf("      |__] |    |__|  \\_/  ");
        gotoxy(80, 27);
        printf("      |    |___ |  |   |   ");

        gotoxy(80, 28);
        printf("      _  _ ____ _    ___  ");
        gotoxy(80, 29);
        printf("__    |__| |___ |    |__] ");
        gotoxy(80, 30);
        printf("      |  | |___ |___ |    ");
    }
}

void selectMenu(){
	hideCursor();
	setup();

	    int selectedItem = 1; // 1 - Play, 2 - Settings

	    while(1) {
	        int joystickInput = readJoystick(); // Read joystick input once per loop iteration

	        if (joystickInput == 8 && selectedItem > 1) {
	            selectedItem--; // Move up in the menu
	            clrscr();
	        }
	        else if (joystickInput == 2 && selectedItem < 2) {
	            selectedItem++;
	            clrscr();// Move down in the menu
	        }

	        drawMenu(selectedItem);
	        drawGameDisplay();

	        delay(100000);
	    }

	    return 0;
}
