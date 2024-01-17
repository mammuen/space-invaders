/*
 * flash.c
 *
 *  Created on: Jan 17, 2024
 *      Author: markus
 */


#include "flash.h"



uint32_t flashreadadd(int address){
	address = address%10;
	uint16_t tempVal;

	uint32_t baseAddress = 0x0800F800;
	tempVal = *(uint16_t *)(baseAddress + address * 2);
	return tempVal;
}

void writeflash(int adress,uint16_t data){

	uint32_t baseAddress = 0x0800F800;


	FLASH_Unlock();
	FLASH_ClearFlag( FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR );
	FLASH_ErasePage( baseAddress + adress * 2);
	FLASH_ProgramHalfWord(baseAddress+ adress * 2, data);
	FLASH_Lock();


}




void readflash(){

	uint32_t baseAddress = 0x0800F800;

	uint16_t tempVal;

	for ( int i = 0 ; i < 10 ; i++ ){
			tempVal = *(uint16_t *)(baseAddress + i * 2); // Read Command
			printf("%d\n", tempVal);
	}

}
