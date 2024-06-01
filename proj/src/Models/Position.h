/**
 * @file Position.h
 * @brief Defines the position structure used to store coordinates and orientation.
 */

#ifndef __POS_H__
#define __POS_H__

#include <lcom/lcf.h>

/**
 * @brief Structure to store position and orientation.
 * 
 * This structure holds the x and y coordinates and the orientation in degrees.
 */
typedef struct {
    int x;           /**< X coordinate of the position */
    int y;           /**< Y coordinate of the position */
    uint16_t deg;    /**< Orientation in degrees */
} position;

#endif // __POS_H__
