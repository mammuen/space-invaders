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
#include "LED.h"
#include <stdbool.h>
#include "player.h"

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

void drawTitleEnd() {
	gotoxy(42, 10);
	printf(" ________  ________  _____ ______   _______           ________  ___      ___ _______   ________     ");
	gotoxy(42, 11);
	printf("|\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\         |\\   __  \\|\\  \\    /  /|\\  ___ \\ |\\   __  \\    ");
	gotoxy(42, 12);
	printf("\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|        \\ \\  \\|\\  \\ \\  \\  /  / | \\   __/|\\ \\  \\|\\  \\   ");
	gotoxy(42, 13);
	printf(" \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__       \\ \\  \\ \\  \\ \\  \\/  / / \\ \\  \\_|/_\\ \\   _  _\\  ");
	gotoxy(42, 14);
	printf("  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\       \\ \\  \\ \\  \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\  \\| ");
	gotoxy(42, 15);
	printf("   \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\       \\ \\_______\\ \\__/ /     \\ \\_______\\ \\__\\\\ _\\ ");
	gotoxy(42, 16);
	printf("    \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______|        \\|_______|\\|__|/       \\|_______|\\|__|\\|__|");

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

void drawEnd(int selectedItem) {
	drawTitleEnd();

    if (selectedItem == 1) {
    	gotoxy(72,25);
    	printf("      ____ ____ _  _ ___ _ _  _ _  _ ____ ");
    	gotoxy(72,26);
    	printf("__    |    |  | |\\ |  |  | |\\ | |  | |___ ");
    	gotoxy(72,27);
    	printf("      |___ |__| | \\|  |  | | \\| |__| |___ ");

    	gotoxy(82,28);
    	printf("      ____ _  _ _ ___ ");
    	gotoxy(82,29);
    	printf("      |___  \\/  |  |  ");
    	gotoxy(82,30);
    	printf("      |___ _/\\_ |  |  ");

    } else {
    	gotoxy(72,25);
    	printf("      ____ ____ _  _ ___ _ _  _ _  _ ____ ");
    	gotoxy(72,26);
    	printf("      |    |  | |\\ |  |  | |\\ | |  | |___ ");
    	gotoxy(72,27);
    	printf("      |___ |__| | \\|  |  | | \\| |__| |___ ");

    	gotoxy(82,28);
    	printf("      ____ _  _ _ ___ ");
    	gotoxy(82,29);
    	printf("__    |___  \\/  |  |  ");
    	gotoxy(82,30);
    	printf("      |___ _/\\_ |  |  ");
    }
}

void drawBack() {
	gotoxy(75, 40);
	printf("      ___  ____ ____ _  _ ");
	gotoxy(75, 41);
	printf("__    |__] |__| |    |_/  ");
	gotoxy(75, 42);
	printf("      |__] |  | |___ | \\_ ");

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
                    backSelected = true;
                    break;
            }
        }

        drawdiff(selectedItem);
        drawGameDisplay(win);

        delay(100000);
    }
    clrscr();
    selectMenu(win);
}


void helpMenu(Window win) {
	uart_init(460800);
    hideCursor();
    setup();
    drawGameDisplay(win);
    drawTitle();
	gotoxy(62,23);
	printf("Basic Controls");
	gotoxy(62,24);
	printf("  Movement: Use JOYSTICK to navigate your spaceship");
	gotoxy(62,25);
	printf("  Shooting: Press RED BUTTON to attack enemies");
	gotoxy(62,26);
	printf("  Special Abilities: Activate them using WHITE BUTTON");

	gotoxy(62,28);
	printf("Objective of the Game");
	gotoxy(62,29);
	printf("  Explore space galaxies, battle enemies and defend the earth");

	gotoxy(62,31);
	printf("Enemies and Bosses");
	gotoxy(62,32);
	printf("  Encounter various enemies and powerful bosses,");
	gotoxy(62,33);
	printf("  each with unique abilities and battle tactics");

	gotoxy(62,35);
	printf("© Space Adventure (Gruppe 16)");

	int selectedItem = 1; // 1 - Back to main menu
	    bool backSelected = false;

	    while (!backSelected) {
	        int joystickInput = readJoystick();

	        if (joystickInput > 8) {
	            switch (selectedItem) {
	                case 1:
	                    clrscr();
	                    backSelected = true;
	                    break;
	            }
	        }

	        drawBack();
	        drawGameDisplay(win);

	        delay(100000);
	    }
	    clrscr();
	    selectMenu(win);
	}

void selectMenu(Window win){
	uart_init(460800);
	hideCursor();
	setup();

	    int selectedItem = 1; // 1 - Play, 2 - Settings

	    while(1) {
	        int joystickInput = readJoystick();

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
	                        diffMenu(win);
	                        break;
	                    }
	                    else if (selectedItem == 2) {
	                        helpMenu(win);
	                        break;
	                    }
	        }

	        drawMenu(selectedItem);
	        drawGameDisplay(win);

	        delay(100000);
	    }
}

void endScreen(Window win, Player P) {
    uart_init(460800);
    hideCursor();
    setup();

    int selectedItem = 1; // 1 - Play again, 2 - Back to main menu
    bool backSelected = false;

    while (!backSelected) {
        int joystickInput = readJoystick();

        if (joystickInput == 8 && selectedItem > 1) {
            clrscr();
            selectedItem--; // Move up in the menu
        } else if (joystickInput == 2 && selectedItem < 2) {
            clrscr();
            selectedItem++; // Move down in the menu
        } else if (joystickInput > 8) {
            switch (selectedItem) {
                case 1:
                    clrscr();
                    diffMenu(win);
                    break;
                case 2:
                    backSelected = true;
                    break;
            }
        }

        gotoxy(90, 20);
        printf("Score: %d", P.score);

        drawEnd(selectedItem);
        drawGameDisplay(win);

        delay(100000);
    }
    clrscr();
    selectMenu(win);
}

