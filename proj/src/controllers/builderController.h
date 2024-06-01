/**
 * @file builderController.h
 * @brief Defines functions for user building and managing obstacles in the arena.
 */

#ifndef __BUILDER_CONTROLLER_
#define __BUILDER_CONTROLLER_

#include "Models/arena.h"
#include "Models/obstacle.h"

/**
 * @brief Adds an obstacle to the arena.
 * 
 * @param arena Pointer to the arena structure.
 * @param x1 X coordinate of the first corner of the obstacle.
 * @param x2 X coordinate of the opposite corner of the obstacle.
 * @param y1 Y coordinate of the first corner of the obstacle.
 * @param y2 Y coordinate of the opposite corner of the obstacle.
 * @return int Status code indicating the result of the addition.
 */
int add_obstacleToArena(Arena* arena, int x1, int x2, int y1, int y2);

/**
 * @brief Processes built obstacles in the arena.
 * 
 * @param arena Pointer to the arena structure.
 * @return int Status code indicating the result of the processing.
 */
int processBuilts(Arena *arena);

#endif // __BUILDER_CONTROLLER_
