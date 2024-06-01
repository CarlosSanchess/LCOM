/**
 * @file Tank.h
 * @brief Defines the tank and enemy tank structures and functions for tank management.
 */

#ifndef __TANK_H__
#define __TANK_H__

#include <lcom/lcf.h>
#include "Position.h"
#include "Models/bullet.h"
#include "Hitbox.h"

#define LEFT -2
#define RIGHT 2
#define UP 1
#define DOWN -1

#define TANK_WIDTH 42
#define TANK_HEIGHT 46

#define MAP_WIDTH 1152
#define MAP_HEIGHT 864

/**
 * @brief Structure to store tank details.
 * 
 * This structure holds the position, health points, speed, movement, rotation,
 * shooting capability, and direction of the tank.
 */
typedef struct {
    position position;   /**< Position and orientation of the tank */
    int hp;              /**< Health points of the tank */
    int speed;           /**< Speed of the tank */
    int wantToMove;      /**< Desired movement direction */
    uint16_t wantToRotate; /**< Desired rotation angle */
    bool canShoot;       /**< Whether the tank can shoot */
    int direction;       /**< Direction of the tank (1 UP, -1 DOWN, 2 RIGHT, -2 LEFT) */
} tank;

/**
 * @brief Structure to store enemy tank details.
 * 
 * This structure holds the position, speed, movement, rotation,
 * shooting capability, and direction of the enemy tank.
 */
typedef struct {
    position position;   /**< Position and orientation of the enemy tank */
    int speed;           /**< Speed of the enemy tank */
    int direction;       /**< Direction of the enemy tank (0: UP, 1: RIGHT, 2: DOWN, 3: LEFT) */
    int currentWaypoint; /**< Current waypoint index */
    bool followingPlayer; /**< Whether the enemy tank is following the player */
    bool canShoot;       /**< Whether the enemy tank can shoot */
} EnemyTank;

/**
 * @brief Creates a new tank.
 * 
 * @param x X coordinate of the tank.
 * @param y Y coordinate of the tank.
 * @param deg Orientation of the tank in degrees.
 * @param hp Health points of the tank.
 * @param speed Speed of the tank.
 * @return Pointer to the created tank.
 */
tank* createTank(int x, int y, uint16_t deg, int hp, int speed);

/**
 * @brief Frees the memory allocated for the tank.
 * 
 * @param tank Pointer to the tank to be freed.
 */
void freeTank(tank *tank);

/**
 * @brief Creates a new enemy tank.
 * 
 * @param x X coordinate of the enemy tank.
 * @param y Y coordinate of the enemy tank.
 * @param deg Orientation of the enemy tank in degrees.
 * @param hp Health points of the enemy tank.
 * @param speed Speed of the enemy tank.
 * @return Pointer to the created enemy tank.
 */
EnemyTank* createEnemyTank(int x, int y, uint16_t deg, int hp, int speed);

/**
 * @brief Frees the memory allocated for the enemy tank.
 * 
 * @param enemyTank Pointer to the enemy tank to be freed.
 */
void freeEnemyTank(EnemyTank *enemyTank);

/**
 * @brief Gets the hitbox of the tank.
 * 
 * @param tank Pointer to the tank.
 * @param hitbox Pointer to the hitbox structure to be filled.
 */
void getTankHitBox(tank* tank, Hitbox *hitbox);

/**
 * @brief Gets the hitbox of the enemy tank.
 * 
 * @param tank Pointer to the enemy tank.
 * @param hitbox Pointer to the hitbox structure to be filled.
 */
void getEnemyTankHitBox(EnemyTank* tank, Hitbox *hitbox);

#endif // __TANK_H__
