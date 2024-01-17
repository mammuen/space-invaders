/*
 * flash.h
 *
 *  Created on: Jan 17, 2024
 *      Author: markus
 */

#ifndef FLASH_H_
#define FLASH_H_


#include <stdio.h>
#include <stdint.h>
#include "stm32f30x.h"

void readflash();

void writeflash(int adress,uint16_t data);
uint32_t flashreadadd(int address);



#endif /* FLASH_H_ */
