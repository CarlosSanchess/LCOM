/**
 * @file obstacle.h
 * @brief Defines the Dynamic Obstacle built by the user hammer, structure and functions for obstacle management.
 */

#ifndef __OBSTACLE__
#define __OBSTACLE__

#include <lcom/lcf.h>

#define TIME 20

/**
 * @brief Structure to store obstacle dimensions, time, and drawing status.
 * 
 * This structure holds the coordinates of the obstacle corners, the time it should be displayed,
 * and whether it should be drawn.
 */
typedef struct {
    int x1;          /**< X coordinate of the first corner */
    int x2;          /**< X coordinate of the opposite corner */
    int y1;          /**< Y coordinate of the first corner */
    int y2;          /**< Y coordinate of the opposite corner */
    uint8_t time;    /**< Time the obstacle should be displayed */
    bool draw;       /**< Whether the obstacle should be drawn */
} Obstacle;

/**
 * @brief Creates a new Obstacle.
 * 
 * @param x1 X coordinate of the first corner.
 * @param x2 X coordinate of the opposite corner.
 * @param y1 Y coordinate of the first corner.
 * @param y2 Y coordinate of the opposite corner.
 * @return Pointer to the created Obstacle.
 */
Obstacle* createObstacle(int x1, int x2, int y1, int y2);

/**
 * @brief Creates an array of Obstacle pointers.
 * 
 * @return Pointer to the created array of Obstacle pointers.
 */
Obstacle** create_obstacle_array();

/**
 * @brief Removes the first obstacle from the array.
 * 
 * @param array Array of Obstacle pointers.
 * @param numObstacles Number of obstacles in the array.
 * @return Pointer to the modified array of Obstacle pointers.
 */
Obstacle** popObstacle(Obstacle** array, size_t numObstacles);

#endif // __OBSTACLE__
