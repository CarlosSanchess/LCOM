/**
 * @file arenaController.h
 * @brief Defines functions for processing the game arena.
 */

#ifndef __ARENA_CONTROLLER_
#define __ARENA_CONTROLLER_

#include "Models/arena.h"
#include "Models/state.h"
#include "tankController.h"
#include "enemyController.h"
#include "bulletController.h"
#include "controllers/gameController.h"

#define NEW_NUM_WAYPOINTS (NUM_WAYPOINTS + 10)

/**
 * @brief Processes the current state of the arena.
 * 
 * @param currentState Pointer to the current game state.
 * @param arena Pointer to the arena structure.
 * @return int Status code indicating the result of the processing.
 */
int processArena(State* currentState, Arena* arena);

#endif // __ARENA_CONTROLLER_
