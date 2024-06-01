/**
 * @file Hitbox.h
 * @brief Defines the Hitbox structure used for collision detection.
 */

#ifndef __HIT_BOX__
#define __HIT_BOX__

#include <stdint.h>

/**
 * @brief Structure to store hitbox dimensions and origin.
 * 
 * This structure holds the coordinates of the hitbox corners and the origin.
 */
typedef struct {
    int x1;          /**< X coordinate of the first corner */
    int x2;          /**< X coordinate of the opposite corner */
    int y1;          /**< Y coordinate of the first corner */
    int y2;          /**< Y coordinate of the opposite corner */
    uint8_t origin;  /**< Origin point of the hitbox */
} Hitbox;

#endif // __HIT_BOX__
