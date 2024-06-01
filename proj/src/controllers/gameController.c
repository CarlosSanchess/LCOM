#include "gameController.h"

static int backgroundFlag = 0;

void resetGame(Arena *arena) {
    freeTank(arena->tank);
    freeEnemyTank(arena->enemyTank);
    arena->tank = createTank(145, 410, 0, 1, 3);
    arena->enemyTank = createEnemyTank(970, 410, 0, 1, 3);
    arena->crosshair->crossHair = 0;
    arena->crosshair->canBuild = true;
    arena->numBuilts = 0;
    arena->numBullets = 0;
    arena->endGame = false;
    arena->bomba.active = false;

    for(size_t i = 0; i < arena->numBullets; i++){
        removeBulletFromBullets(arena->bullets, arena->numBullets, i);
    }
    for(size_t i = 0; i < arena->numBuilts; i++){
        popObstacle(arena->builts, arena->numBuilts);
    }
}

int changeToMenu(State* gameState, Arena* arena){

    if (*gameState == inGame) {
            *gameState = inMenu;
            backgroundFlag = 0;
            resetGame(arena);
            drawMenuBackGround();
            return 0;
        } else if (*gameState == inMenu) {
            return 1;
        }

    return 0;
}

int changeBackground(){
    if(backgroundFlag == 0){
        drawGameBackGround();
        backgroundFlag = 1;
    }
    return 0;
}

int changeToHighScore(State* gameState, HighScore score){

    if(*gameState == inMenu && backgroundFlag == 0){
        *gameState = Score;
        drawHighScorePage(score);
        backgroundFlag = 1;
        return 0;
    }
    return 1;
}
