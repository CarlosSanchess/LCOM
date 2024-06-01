/**
 * @file collisionController.h
 * @brief Defines functions for handling collisions in the arena.
 */

#ifndef __COLLISION_
#define __COLLISION_

#include <lcom/lcf.h>

#include "Views/views.h"
#include "Models/bullet.h"
#include "Models/Tank.h"
#include "Models/arena.h"
#include "Models/Position.h"
#include "Models/Hitbox.h"
#include "controllers/gameController.h"
#include "dev_interface/devices/graphics_const.h"

/**
 * @brief Checks if two hitboxes collide.
 * 
 * @param a The first hitbox.
 * @param b The second hitbox.
 * @return bool True if the hitboxes collide, false otherwise.
 */
bool checkCollision(Hitbox a, Hitbox b);

/**
 * @brief Processes collisions in the arena.
 * 
 * @param arena Pointer to the arena structure.
 * @param index Index of the current object.
 * @param tankHB Hitbox of the player's tank.
 * @param enemyTankHB Hitbox of the enemy tank.
 * @param bulletHB Hitbox of the bullet.
 * @return int Status code indicating the result of the processing.
 */
int processCollisions(Arena* arena, size_t index, Hitbox tankHB, Hitbox enemyTankHB, Hitbox bulletHB);

#endif // __COLLISION_
