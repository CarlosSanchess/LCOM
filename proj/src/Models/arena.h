/**
 * @file arena.h
 * @brief This file contains the data structure and function declarations for the Models of the game arena.
 * 
 * It encapsulates the state and logic of the game, providing a clear separation between the 
 * game's state management and its visual representation. 
 */

#ifndef __ARENA__
#define __ARENA__

#include "Tank.h"
#include "mouse.h"
#include "obstacle.h"
#include "bomb.h"

#define NUM_OBSTACLES 12   /**< Number of static obstacles in the arena */
#define ARENA_BORDER 50    /**< Border size of the arena */

/**
 * @struct Arena
 * @brief Represents the game arena containing all game elements.
 * 
 * This structure holds all the relevant data for the game arena, including tanks, obstacles,
 * bullets, and the current score.
 */
typedef struct {
    tank* tank;                    /**< The player's tank */
    EnemyTank* enemyTank;          /**< The enemy tank */
    MouseInfo* crosshair;          /**< Mouse information */
    int width;                     /**< Width of the arena */
    int height;                    /**< Height of the arena */
    Obstacle obstacles[NUM_OBSTACLES]; /**< Array of static obstacles */

    Obstacle** builts;             /**< Dynamic array of built obstacles */
    size_t numBuilts;              /**< Number of built obstacles */

    bullet** bullets;              /**< Dynamic array of bullets */
    size_t numBullets;             /**< Number of bullets */

    int curr_score;                /**< Current score of the player */

    bool endGame;                  /**< Flag indicating if the game has ended */

    bomb bomba;                    /**< Bomb information */
} Arena;

/**
 * @brief Creates and initializes a new game arena.
 * 
 * This function allocates memory for a new Arena structure and initializes it with 
 * default values, including setting up the player's tank, enemy tank, obstacles, and other 
 * game elements.
 * 
 * @param width Width of the arena.
 * @param height Height of the arena.
 * @param mouseInfo Pointer to the MouseInfo structure for crosshair handling.
 * @return Arena* Pointer to the newly created Arena structure, or NULL if memory allocation fails.
 */
Arena* createArena(int width, int height, MouseInfo *mouseInfo);

/**
 * @brief Destroys a game arena, freeing allocated memory.
 * 
 * This function cleans up and frees all memory allocated for the Arena structure,
 * including the tanks and any dynamically allocated arrays.
 * 
 * @param arena Pointer to the Arena structure to be destroyed.
 */
void destroyArena(Arena *arena);

#endif // __ARENA__
