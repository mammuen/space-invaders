/*
 * menu.h
 *
 *  Created on: 8. jan. 2024
 *      Author: doube
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdint.h>
#include <stdio.h>
#include "stm32f30x.h"
#include "game.h"

void drawMenu(int selectedItem);
void drawdiff(int selectedItem);
void selectMenu(Window win);
void helpMenu(Window win);
void diffMenu(Window win);
void delay(uint32_t count);
void drawTitle();
void endScreen(Window win);
void drawEnd();
void drawTitleEnd();
void drawBack();

#endif /* MENU_H_ */
