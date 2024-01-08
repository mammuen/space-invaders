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
void selectMenu();
void delay(uint32_t count);

#endif /* MENU_H_ */
