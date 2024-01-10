/*
 * enemies.h
 *
 *  Created on: Jan 10, 2024
 *      Author: markus
 */

#ifndef ENEMIES_H_
#define ENEMIES_H_


Enemy* initEnemy();
void drawEnemies(Enemy*);
int updateEnemies(Enemy*);
void printEnemy(int x,int y);


extern char enemyPrint[3][3];


#endif /* ENEMIES_H_ */
