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
#include <stdbool.h>

void delay(uint32_t count) {
    while (count--) {
    }
}

void drawTitle() {
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

void drawMenu(int selectedItem) {
	drawTitle();

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

void drawdiff(int selectedItem) {
	drawTitle();

	    if (selectedItem == 1) {
	    	gotoxy(75, 25);
	    	printf("      ____ ____ ____ _   _ ");
	    	gotoxy(75, 26);
	    	printf("__    |___ |__| [__   \\_/  ");
	    	gotoxy(75, 27);
	    	printf("      |___ |  | ___]   |   ");

	    	gotoxy(75, 28);
	    	printf("      _  _ ____ ____ _  _ ____ _    ");
	    	gotoxy(75, 29);
	    	printf("      |\\ | |  | |__/ |\\/| |__| |    ");
	    	gotoxy(75, 30);
	    	printf("      | \\| |__| |  \\ |  | |  | |___ ");

	    	gotoxy(75, 31);
	    	printf("      _  _ ____ ____ ___  ");
	    	gotoxy(75, 32);
	    	printf("      |__| |__| |__/ |  \\ ");
	    	gotoxy(75, 33);
	    	printf("      |  | |  | |  \\ |__/ ");

	    	gotoxy(75, 36);
	    	printf("      ___  ____ ____ _  _ ");
	    	gotoxy(75, 37);
	    	printf("      |__] |__| |    |_/  ");
	    	gotoxy(75, 38);
	    	printf("      |__] |  | |___ | \\_ ");

	    } else if (selectedItem == 2) {
	    	gotoxy(75, 25);
	    	printf("      ____ ____ ____ _   _ ");
	    	gotoxy(75, 26);
	    	printf("      |___ |__| [__   \\_/  ");
	    	gotoxy(75, 27);
	    	printf("      |___ |  | ___]   |   ");

	    	gotoxy(75, 28);
	    	printf("      _  _ ____ ____ _  _ ____ _    ");
	    	gotoxy(75, 29);
	    	printf("__    |\\ | |  | |__/ |\\/| |__| |    ");
	    	gotoxy(75, 30);
	    	printf("      | \\| |__| |  \\ |  | |  | |___ ");

	    	gotoxy(75, 31);
	    	printf("      _  _ ____ ____ ___  ");
	    	gotoxy(75, 32);
	    	printf("      |__| |__| |__/ |  \\ ");
	    	gotoxy(75, 33);
	    	printf("      |  | |  | |  \\ |__/ ");

	    	gotoxy(75, 36);
	    	printf("      ___  ____ ____ _  _ ");
	    	gotoxy(75, 37);
	    	printf("      |__] |__| |    |_/  ");
	    	gotoxy(75, 38);
	    	printf("      |__] |  | |___ | \\_ ");

	    } else if (selectedItem == 3) {
	    	gotoxy(75, 25);
	    	printf("      ____ ____ ____ _   _ ");
	    	gotoxy(75, 26);
	    	printf("      |___ |__| [__   \\_/  ");
	    	gotoxy(75, 27);
	    	printf("      |___ |  | ___]   |   ");

	    	gotoxy(75, 28);
	    	printf("      _  _ ____ ____ _  _ ____ _    ");
	    	gotoxy(75, 29);
	    	printf("      |\\ | |  | |__/ |\\/| |__| |    ");
	    	gotoxy(75, 30);
	    	printf("      | \\| |__| |  \\ |  | |  | |___ ");

	    	gotoxy(75, 31);
	    	printf("      _  _ ____ ____ ___  ");
	    	gotoxy(75, 32);
	    	printf("__    |__| |__| |__/ |  \\ ");
	    	gotoxy(75, 33);
	    	printf("      |  | |  | |  \\ |__/ ");

	    	gotoxy(75, 36);
	    	printf("      ___  ____ ____ _  _ ");
	    	gotoxy(75, 37);
	    	printf("      |__] |__| |    |_/  ");
	    	gotoxy(75, 38);
	    	printf("      |__] |  | |___ | \\_ ");

	    } else if (selectedItem == 4) {
	    	gotoxy(75, 25);
	    	printf("      ____ ____ ____ _   _ ");
	    	gotoxy(75, 26);
	    	printf("      |___ |__| [__   \\_/  ");
	    	gotoxy(75, 27);
	    	printf("      |___ |  | ___]   |   ");

	    	gotoxy(75, 28);
	    	printf("      _  _ ____ ____ _  _ ____ _    ");
	    	gotoxy(75, 29);
	    	printf("      |\\ | |  | |__/ |\\/| |__| |    ");
	    	gotoxy(75, 30);
	    	printf("      | \\| |__| |  \\ |  | |  | |___ ");

	    	gotoxy(75, 31);
	    	printf("      _  _ ____ ____ ___  ");
	    	gotoxy(75, 32);
	    	printf("      |__| |__| |__/ |  \\ ");
	    	gotoxy(75, 33);
	    	printf("      |  | |  | |  \\ |__/ ");

	    	gotoxy(75, 36);
	    	printf("      ___  ____ ____ _  _ ");
	    	gotoxy(75, 37);
	    	printf("__    |__] |__| |    |_/  ");
	    	gotoxy(75, 38);
	    	printf("      |__] |  | |___ | \\_ ");
	    }

}

void diffMenu(Window win) {
    uart_init(460800);
    hideCursor();
    setup();

    int selectedItem = 1; // 1 - easy, 2 - normal, 3 - hard, 4 - back
    bool backSelected = false; // Flag to check if back is selected

    while (!backSelected) {
        int joystickInput = readJoystick(); // Read joystick input once per loop iteration

        if (joystickInput == 8 && selectedItem > 1) {
            clrscr();
            selectedItem--; // Move up in the menu
        } else if (joystickInput == 2 && selectedItem < 4) {
            clrscr();
            selectedItem++; // Move down in the menu
        } else if (joystickInput > 8) {
            // Handle menu item selection
            switch (selectedItem) {
                case 1:
                    // EASY MODE
                    // add function
                    break;
                case 2:
                    // NORMAL MODE
                    // add function
                    break;
                case 3:
                    // HARD MODE
                    // add function
                    break;
                case 4:
                    // Back to selectMenu
                    backSelected = true;
                    break;
            }
        }

        drawdiff(selectedItem);
        drawGameDisplay(win);

        delay(100000);
    }
    clrscr();
    selectMenu(win); // Call selectMenu after exiting the while loop
}


void helpMenu(Window win) {
	uart_init(460800);
    hideCursor();
    setup();
    drawGameDisplay(win);
}

void selectMenu(Window win){
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

	        else if (joystickInput > 8) {
	                    clrscr();

	                    if (selectedItem == 1) {
	                        // Open difficulties menu
	                        diffMenu(win);
	                        break;
	                    }
	                    else if (selectedItem == 2) {
	                        // Open help menu
	                        helpMenu(win);
	                        break;
	                    }
	        }

	        drawMenu(selectedItem);
	        drawGameDisplay(win);

	        delay(100000);
	    }
}

void showTitle() {

}
