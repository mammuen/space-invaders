/*
 * asteroid.c
 *
 *  Created on: 10 янв. 2024 г.
 *      Author: doube
 */
#include "asteroid.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ansi.h"


Asteroid* initAsteroid(int count) {
    Asteroid* asteroids = malloc(count * sizeof(Asteroid));

    if (asteroids != NULL) {
        for (int i = 0; i < count; i++) {
            int validPosition;
            do {
                validPosition = 1;
                // Set the initial X positions in the range [59, 118]
                asteroids[i].x = (rand() % 60) + 59;
                // We set the initial Y positions only in the range [55, 100]
                asteroids[i].y = (rand() % 46) + 55;

                // Checking that the new asteroid is not too close to existing asteroids DO NOT TOUCH IT!!!
                for (int j = 0; j < i; j++) {
                    int dx = asteroids[i].x - asteroids[j].x;
                    int dy = asteroids[i].y - asteroids[j].y;
                    int distanceSquared = dx * dx + dy * dy;

                    if (distanceSquared < 100) {
                        validPosition = 0;
                        break;
                    }
                }
            } while (!validPosition);

            // Size of asteroids
            asteroids[i].size = (rand() % 5) + 4;
            asteroids[i].health = 2; // Start health
        }
    }

    return asteroids;
}


void updateAsteroid(Asteroid* asteroids, int count) {
    for (int i = 0; i < count; i++) {
        if (asteroids[i].health > 0) {
        	// Check if the asteroid has reached the upper limit
            if (asteroids[i].y <= -3) {
            	// Deleting the current asteroid
                asteroids[i].health = 0;

                int validPosition;
                do {
                    validPosition = 1;
                    // Creation of a new asteroid
                    asteroids[i].x = (rand() % 60) + 59; // New X position in range [59, 118]
                    asteroids[i].y = (rand() % 46) + 55; // New Y position in range [55, 100]
                    asteroids[i].size = (rand() % 5) + 4; // New size from 4 to 8
                    asteroids[i].health = 2; // New number of lives

                    // Checking a new asteroid for intersection with other asteroids
                    for (int j = 0; j < count; j++) {
                        if (j != i) {
                            int dx = asteroids[i].x - asteroids[j].x;
                            int dy = asteroids[i].y - asteroids[j].y;
                            int distanceSquared = dx * dx + dy * dy;

                            if (distanceSquared < 100) {
                                validPosition = 0;
                                break;
                            }
                        }
                    }
                } while (!validPosition);
            } else {
                asteroids[i].y -= 1; // Moving the asteroid up
                // I think it's possible to add additional logic such as collision detection
            }
        }
    }
}


void drawAsteroid(Asteroid* asteroids, int count) {
    for (int i = 0; i < count; i++) {
        if (asteroids[i].health > 0) {
            gotoxy(asteroids[i].x, asteroids[i].y);

            // Draw the asteroid with its size
            for (int j = 0; j < asteroids[i].size; j++) {
                for (int k = 0; k < asteroids[i].size; k++) {
                    printf("#");
                }
                if (j < asteroids[i].size - 1) {
                    // Move to the next line for drawing the asteroid
                    gotoxy(asteroids[i].x, asteroids[i].y + j + 1);
                }
            }
        }
    }
}
