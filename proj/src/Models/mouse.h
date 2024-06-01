/**
 * @file mouse.h
 * @brief Defines the MouseInfo structure and includes resources for mouse handling.
 */

#ifndef __MOUSE__
#define __MOUSE__

#include "Models/Position.h"
#include "dev_interface/devices/video_gr.h"
#include "xpm/cursor.xpm"
#include "xpm/crosshair.xpm"

/**
 * @brief Structure to store mouse information.
 * 
 * This structure holds the current position of the mouse, the state of the crosshair,
 * and whether building is allowed.
 */
typedef struct {
    position mousePosition; /**< Current position of the mouse */
    uint8_t crossHair;      /**< State of the crosshair */
    bool canBuild;          /**< Whether building is allowed */
} MouseInfo;

#endif // __MOUSE__
