/**
 * @file tankController.h
 * @brief Defines functions for controlling tank movements and interactions based on the keyboard.
 * W moves frontwards, S moves backwards, A rotates left, D rotates right.
 */

#ifndef TANKCONTROLLER_H
#define TANKCONTROLLER_H

#include "Models/Tank.h"
#include "Models/arena.h"

/**
 * @brief Checks if a tank can move to the specified position.
 * 
 * @param x X coordinate of the new position.
 * @param y Y coordinate of the new position.
 * @param obstacles Array of obstacles.
 * @param numObstacles Number of obstacles.
 * @param builds Array of builds.
 * @param numBuilds Number of builds.
 * @return bool True if the tank can move to the new position, false otherwise.
 */
bool canMove(int x, int y, Obstacle obstacles[], int numObstacles, Obstacle** builds, size_t numBuilds);

/**
 * @brief Moves a tank backwards.
 * 
 * @param tank Pointer to the tank structure.
 * @param obstacles Array of obstacles.
 * @param numObstacles Number of obstacles.
 * @param builds Array of builds.
 * @param numBuilds Number of builds.
 * @return int Returns 0 on success, non-zero on failure.
 */
int moveDown(tank *tank, Obstacle obstacles[], int numObstacles, Obstacle** builds, size_t numBuilds);

/**
 * @brief Moves a tank frontwards.
 * 
 * @param tank Pointer to the tank structure.
 * @param obstacles Array of obstacles.
 * @param numObstacles Number of obstacles.
 * @param builds Array of builds.
 * @param numBuilds Number of builds.
 * @return int Returns 0 on success, non-zero on failure.
 */
int moveUP(tank *tank, Obstacle obstacles[], int numObstacles, Obstacle** builds, size_t numBuilds);

/**
 * @brief Rotates the tank to the right.
 * 
 * @param tank Pointer to the tank structure.
 * @return int Returns 0 on success, non-zero on failure.
 */
int moveRight(tank *tank);

/**
 * @brief Rotates the tank to the left.
 * 
 * @param tank Pointer to the tank structure.
 * @return int Returns 0 on success, non-zero on failure.
 */
int moveLeft(tank *tank);

/**
 * @brief Processes the tank's actions.
 * 
 * @param tank Pointer to the tank structure.
 * @param obstacles Array of obstacles.
 * @param numObstacles Number of obstacles.
 * @return int Returns 0 on success, non-zero on failure.
 */
int processTank(tank* tank, Obstacle obstacles[], int numObstacles);

#endif // TANKCONTROLLER_H
