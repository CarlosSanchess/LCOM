#include "timerController.h"

//todo same timer count for all
void timer_increment(){
    timerCounter++;
}
int handleDelayedEvents(Arena* arena, MouseInfo* mouseInfo){
    
    handleDelayedShooting(arena->tank);
    if(!mouseInfo->canBuild){handleDelayedMouse(mouseInfo);}
    handleDelayedBuildings(arena->builts, arena->numBuilts);
    handleDelayedEnemyShooting(arena->enemyTank);
    handleDelayedBomb(arena);
    
    return 0;
}

int handleDelayedShooting(tank *tank) {
    static int delayShooting = 0;
    if (!tank->canShoot) {
        delayShooting++;
        if (delayShooting >= SHOOTD) {
            tank->canShoot = true;
            delayShooting = 0; 
        }
    } else {
        delayShooting = 0; 
    }

    return 0;
}
void handleDelayedMouse(MouseInfo* mouseInfo){
    static int delayMouse = 0;
    delayMouse++;
    if(delayMouse >= DRAWD){
        mouseInfo->canBuild = true;
        delayMouse = 0;
    }
}

void handleDelayedBuildings(Obstacle** obstacles, size_t numObstacles){
    static int delayBuildings = 0;
    delayBuildings++;
    if(delayBuildings >= BUILDD){
        for(size_t i = 0; i < numObstacles; i++){
            obstacles[i]->time--;
            obstacles[i]->draw = true;
        }
        delayBuildings = 0;
    }
}

int handleDelayedEnemyShooting(EnemyTank *enemyTank) {
    static int delayShootingEnemy = 0;
    if (!enemyTank->canShoot) {
        delayShootingEnemy++;
        if (delayShootingEnemy >= SHOOTD) {
            enemyTank->canShoot = true;
            delayShootingEnemy = 0; 
        }
    } else {
        delayShootingEnemy = 0; 
    }

    return 0;
}

void handleDelayedBomb(Arena* arena){
     static int delayBomb = 0;
    if (arena->bomba.active == true) {
        delayBomb++;
        if (delayBomb >= BOMBD) {
            printf("endgame");
            arena->endGame = true;
            delayBomb = 0; 
        }
    } else {
        delayBomb = 0;
    }
}

