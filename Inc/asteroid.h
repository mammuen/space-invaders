/*
 * asteroid.h
 *
 *  Created on: 10 янв. 2024 г.
 *      Author: doube
 */

#ifndef ASTEROID_H_
#define ASTEROID_H_

typedef struct {
    int x;
    int y;
    int size;
    int health;
} Asteroid;

Asteroid* initAsteroid(int count);
void updateAsteroid(Asteroid* asteroids, int count);
void drawAsteroid(Asteroid* asteroids, int count);

#endif /* ASTEROID_H_ */
