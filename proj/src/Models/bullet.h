/**
 * @file bullet.h
 * @brief This file contains the data structure and functions for handling bullets in the game.
 * 
 */

#ifndef __BULLET__
#define __BULLET__

#include "Position.h"
#include "Hitbox.h"
#include "dev_interface/devices/video_gr.h"

#define BULLET_SPEED 5
#define BULLET_WIDTH 10
#define BULLET_HEIGHT 34

#define PLAYER 1
#define ENEMY 2

/**
 * @struct bullet
 * @brief Represents a bullet in the game.
 * 
 * This structure holds the position, speed, and origin of a bullet. It is used to manage
 * bullets fired in the game, tracking their location, speed, and whether they were fired by a player or an enemy.
 */
typedef struct {
    position position;  /**< The position of the bullet in the arena */
    int speed;          /**< The speed of the bullet */
    uint8_t origin;     /**< The origin of the bullet, indicating whether it was fired by a player or an enemy */
} bullet;

/**
 * @brief Creates a new bullet.
 * 
 * @param pos The position of the bullet.
 * @param speed The speed of the bullet.
 * @param origin The origin of the bullet (PLAYER or ENEMY).
 * @return A pointer to the newly created bullet.
 */
bullet* createBullet(position pos, int speed, uint8_t origin);

/**
 * @brief Removes a bullet from an array of bullets.
 * 
 * @param bullets The array of bullets.
 * @param numBullets The number of bullets in the array.
 * @param index The index of the bullet to remove.
 * @return A new array of bullets with the specified bullet removed.
 */
bullet** removeBulletFromBullets(bullet** bullets, size_t numBullets, size_t index);

/**
 * @brief Frees the memory allocated for a bullet.
 * 
 * @param b The bullet to free.
 */
void freebullet(bullet* b);

/**
 * @brief Creates a hitbox for a bullet.
 * 
 * @param b The bullet for which to create the hitbox.
 * @param hitbox The hitbox to be created.
 */
void createBulletHitbox(bullet* b, Hitbox* hitbox);

#endif // __BULLET__
