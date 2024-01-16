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
#include "player.h"

void drawMenu(int selectedItem);
void drawdiff(int selectedItem);
int selectMenu(Window win);
void helpMenu(Window win);
int  diffMenu(Window win);
void delay(uint32_t count);
void drawTitle();
int endScreen(Window win, Player P,int difficulty);
void drawEnd();
void drawTitleEnd();
void drawBack();

#endif /* MENU_H_ */
