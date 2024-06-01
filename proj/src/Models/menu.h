/**
 * @file menu.h
 * @brief Defines the Menu structure used for menu management.
 */

#ifndef __MENU__
#define __MENU__

#include "xpm/grenade.xpm"
#include "dev_interface/devices/video_gr.h"

/**
 * @brief Structure to store menu state and coordinates.
 * 
 * This structure holds the currently selected menu item, whether the game is in progress,
 * and coordinates for drawing the grenade.
 */
typedef struct {
    int selected;    /**< Currently selected menu item */
    bool InGame;     /**< Whether the game is in progress */
    int coord[3][2]; /**< Coordinates for drawing the grenade */
} Menu;

#endif // __MENU__
