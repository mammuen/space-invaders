/*
 * collision.c
 *
 *  Created on: Jan 9, 2024
 *      Author: markus
 */

#include "collision.h"



int checkcollision(uint8_t* collision, Player p, Asteriod a, Enemy e)
{

	return 0;
}


uint8_t* initCollision(){
	uint8_t* line = malloc(180*sizeof(uint8_t));
	free(line);
	return line;
}

void cleararray(uint8_t* collision){
	memset(collision, 0, 180);
}











//= {
//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
//}
