/**
 * @file timerController.h
 * @brief Declares functions for handling timer-based events in the game.
 */

#ifndef __TIMER_CONTROLLER__
#define __TIMER_CONTROLLER__

#include "../Models/mouse.h"
#include "../Models/arena.h"

#define SHOOTD 120   ///< Delay for shooting 
#define DRAWD 600    ///< Delay for drawing 
#define BUILDD 60    ///< Delay for building 
#define BOMBD 25     ///< Delay for bomb activation

static unsigned int timerCounter = 0; ///< Counter for timer events

/**
 * @brief Increments the global timer counter.
 */
void timer_increment();

/**
 * @brief Handles all delayed events in the game.
 * 
 * @param arena Pointer to the Arena structure.
 * @param mouseInfo Pointer to the MouseInfo structure.
 * @return int Returns 0 on success.
 */
int handleDelayedEvents(Arena* arena, MouseInfo* mouseInfo);

/**
 * @brief Handles the delay for tank shooting.
 * 
 * @param tank Pointer to the tank structure.
 * @return int Returns 0 on success.
 */
int handleDelayedShooting(tank *tank);

/**
 * @brief Handles the delay for mouse-related actions.
 * 
 * @param mouseInfo Pointer to the MouseInfo structure.
 */
void handleDelayedMouse(MouseInfo* mouseInfo);

/**
 * @brief Handles the delay for building-related actions.
 * 
 * @param obstacles Array of pointers to Obstacle structures.
 * @param numObstacles Number of obstacles in the array.
 */
void handleDelayedBuildings(Obstacle** obstacles, size_t numObstacles);

/**
 * @brief Handles the delay for enemy tank shooting.
 * 
 * @param enemyTank Pointer to the EnemyTank structure.
 * @return int Returns 0 on success.
 */
int handleDelayedEnemyShooting(EnemyTank *enemyTank);

/**
 * @brief Handles the delay for bomb activation.
 * 
 * @param arena Pointer to the Arena structure.
 */
void handleDelayedBomb(Arena* arena);

#endif // __TIMER_CONTROLLER__
