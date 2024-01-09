/*
 * menu.c
 *
 *  Created on: 8. jan. 2024
 *      Author: doube
 */

#include "menu.h"
#include "game.h"
#include "ansi.h"
#include "joystick.h"
#include "stm32f30x_conf.h"
#include "30010_io.h"

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
    	gotoxy(75,25);
        printf("      ___  _    ____ _   _ ");
        gotoxy(75,26);
        printf("__    |__] |    |__|  \\_/  ");
        gotoxy(75,27);
        printf("      |    |___ |  |   |   ");

        gotoxy(75,28);
        printf("      _  _ ____ _    ___  ");
        gotoxy(75,29);
        printf("      |__| |___ |    |__] ");
        gotoxy(75,30);
        printf("      |  | |___ |___ |    ");

    } else {
        gotoxy(75, 25);
        printf("      ___  _    ____ _   _ ");
        gotoxy(75, 26);
        printf("      |__] |    |__|  \\_/  ");
        gotoxy(75, 27);
        printf("      |    |___ |  |   |   ");

        gotoxy(75, 28);
        printf("      _  _ ____ _    ___  ");
        gotoxy(75, 29);
        printf("__    |__| |___ |    |__] ");
        gotoxy(75, 30);
        printf("      |  | |___ |___ |    ");
    }
}

void drawdiff() {
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
}

void helpMenu() {
	uart_init(460800);
    hideCursor();
    setup();
    drawGameDisplay();

    while (1) {
        int joystickInput = readJoystick(); // Read joystick input once per loop iteration

        if (joystickInput > 8) {
            clrscr();
            selectMenu();
            break;
        }
    }

    // After exiting the help menu, call selectMenu
    selectMenu();
}

void diffMenu() {
	uart_init(460800);
    hideCursor();
    setup();



}

void selectMenu(){
	uart_init(460800);
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
	            clrscr(); // Move down in the menu
	        }

	        else if (joystickInput > 8 && selectedItem == 2) {
	        	clrscr();
	        	helpMenu(); // Open help
	        	break;
	        }

	        else if (joystickInput > 8 && selectedItem == 1) {
	        	clrscr();
	        	diffMenu(); // Open difficulties
	        	break;
	        }

	        drawMenu(selectedItem);
	        drawGameDisplay();

	        delay(100000);
	    }
}

void showTitle() {

}
