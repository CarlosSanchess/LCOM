/**
 * @file bomb.h
 * @brief This file contains the data structure for handling bomb element model.
 * 
 * The Bomb structure is a crucial part of the end game visuals since it represents a victory/loss.
 */

#ifndef __BOMB__
#define __BOMB__

#include "Models/Position.h"

/**
 * @struct bomb
 * @brief Represents a bomb in the game.
 * 
 * This structure holds the position and active status of a bomb.
 */
typedef struct 
{   
    position pos;  /**< The position of the bomb in the arena */
    bool active;   /**< Status of the bomb, indicating whether it is active */
} bomb;

#endif // __BOMB__
