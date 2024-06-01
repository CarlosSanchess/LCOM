/**
 * @file bulletController.h
 * @brief Defines functions for managing bullets in the arena.
 */

#ifndef __BULLET_CONTROLLER__
#define __BULLET_CONTROLLER__

#include "Models/bullet.h"
#include <lcom/lcf.h>
#include "Models/arena.h"
#include "controllers/bulletController.h"
#include "controllers/builderController.h"
#include "controllers/collisionController.h"

#define GREEN_TANK 1
#define RED_TANK 2

/**
 * @brief Adds a bullet to the arena.
 * 
 * @param arena Pointer to the arena structure.
 * @param tankColor Color of the tank that fired the bullet.
 * @return int Status code indicating the result of the addition.
 */
int addBulletToArena(Arena* arena, int tankColor);

/**
 * @brief Moves a bullet.
 * 
 * @param bullet Pointer to the bullet structure.
 * @return int Status code indicating the result of the movement.
 */
int bulletMove(bullet* bullet);

/**
 * @brief Processes all bullets in the arena.
 * 
 * @param arena Pointer to the arena structure.
 * @return int Status code indicating the result of the processing.
 */
int processBullets(Arena* arena);

/**
 * @brief Processes built structures in the arena.
 * 
 * @param arena Pointer to the arena structure.
 * @return int Status code indicating the result of the processing.
 */
int processBuilts(Arena *arena);

#endif // __BULLET_CONTROLLER__
