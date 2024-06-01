/**
 * @file views.h
 * @brief This file contains function declarations used to draw various elements of the game.
 * 
 * This architecture provides a clear separation between the visual representation of the game elements and the underlying game logic.
 */
#ifndef __VIEWS__
#define __VIEWS__

#include "Models/arena.h"
#include "Models/menu.h"
#include "Models/Tank.h"
#include "Models/mouse.h"
#include "Models/bullet.h"
#include "Models/HighScore.h"
#include "dev_interface/devices/video_gr.h"
#include "../xpm/bullet.xpm"
#include "../xpm/tank_green.xpm"
#include "../xpm/tank_red.xpm"
#include "../xpm/bomb.xpm"
#include "../xpm/highscore.xpm"
#include "../xpm/menuScore.xpm"
#include "../xpm/numbers/number0.xpm"
#include "../xpm/numbers/number1.xpm"
#include "../xpm/numbers/number2.xpm"
#include "../xpm/numbers/number3.xpm"
#include "../xpm/numbers/number4.xpm"
#include "../xpm/numbers/number5.xpm"
#include "../xpm/numbers/number6.xpm"
#include "../xpm/numbers/number7.xpm"
#include "../xpm/numbers/number8.xpm"
#include "../xpm/numbers/number9.xpm"
#include "../xpm/numbers/number0resize.xpm"
#include "../xpm/numbers/number1resize.xpm"
#include "../xpm/numbers/number2resize.xpm"
#include "../xpm/numbers/number3resize.xpm"
#include "../xpm/numbers/number4resize.xpm"
#include "../xpm/numbers/number5resize.xpm"
#include "../xpm/numbers/number6resize.xpm"
#include "../xpm/numbers/number7resize.xpm"
#include "../xpm/numbers/number8resize.xpm"
#include "../xpm/numbers/number9resize.xpm"
#include "../xpm/blocks/block1.xpm"
#include "../xpm/blocks/block2.xpm"
#include "../xpm/blocks/block3.xpm"
#include "../xpm/blocks/block4.xpm"
#include "../xpm/blocks/block5.xpm"
#include "../xpm/blocks/block6.xpm"
#include "../xpm/blocks/block7.xpm"
#include "../xpm/blocks/block8.xpm"
#include "../xpm/blocks/block9.xpm"
#include "../xpm/blocks/block10.xpm"
#include "../xpm/martelo.xpm"
#include "../xpm/menu.xpm"
#include "../xpm/mapa1.xpm"
#include "../Models/bomb.h"

/**
 * @brief Draws the menu screen.
 * 
 * @param menu The menu to draw.
 * @param score The high score to display on the menu.
 * @return int Returns 0 on success.
 */
int drawMenu(Menu menu, HighScore score);

/**
 * @brief Draws the arena screen.
 * 
 * @param arena The arena to draw.
 * @return int Returns 0 on success.
 */
int drawArena(Arena arena);

/**
 * @brief Draws the player tank on the screen.
 * 
 * @param tank The tank to draw.
 * @return int Returns 0 on success.
 */
int drawTank(tank *tank);

/**
 * @brief Draws an enemy tank on the screen.
 * 
 * @param tank The enemy tank to draw.
 * @return int Returns 0 on success.
 */
int drawEnemyTank(EnemyTank *tank);

/**
 * @brief Draws the mouse cursor on the screen.
 * 
 * @param mouse The mouse information to draw.
 * @return int Returns 0 on success.
 */
int drawMouse(MouseInfo mouse);

/**
 * @brief Draws a bullet on the screen.
 * 
 * @param b The bullet to draw.
 * @return int Returns 0 on success.
 */
int drawBullet(bullet b);

/**
 * @brief Draws all bullets in the arena.
 * 
 * @param arena The arena containing the bullets.
 * @return int Returns 0 on success.
 */
int drawBullets(Arena arena);

/**
 * @brief Draws dynamically built obstacles (by the user hammer) in the arena, they fade after 10 secs.
 * 
 * @param builds Obstacle to draw.
 * @param numBuilts Number of obstacles.
 * @return int Returns 0 on success.
 */
int drawBuilds(Obstacle** builds, size_t numBuilts);

/**
 * @brief Draws a bomb on the screen after one of the tanks die.
 * 
 * @param bomba The bomb to draw.
 * @return int Returns 0 on success.
 */
int drawBomb(bomb bomba);

/**
 * @brief Draws the high score screen.
 * 
 * @param score The high score to display.
 * @return int Returns 0 on success.
 */
int drawHighScore(HighScore score);

/**
 * @brief Draws the player's score on the screen.
 * 
 * @param score The score to display.
 * @return int Returns 0 on success.
 */
int drawScore(HighScore score);

/**
 * @brief Draws the rtc info about the highscore on the screen.
 * 
 * @param score The time to display is inside the struct.
 * @return int Returns 0 on success.
 */
int drawChrono(HighScore score);

/**
 * @brief Draws the menu background.
 * 
 * @return int Returns 0 on success.
 */
int drawMenuBackGround();

/**
 * @brief Draws the game background.
 * 
 * @return int Returns 0 on success.
 */
int drawGameBackGround();

/**
 * @brief Draws the score menu background.
 * 
 * @return int Returns 0 on success.
 */
int drawScoreBackGround();

/**
 * @brief Draws the whole HighScore Page.
 * 
 * @return int Returns 0 on success.
 */
int drawHighScorePage(HighScore score);



#endif

