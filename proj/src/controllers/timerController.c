#include "timerController.h"


void timer_increment(){
    timerCounter++;
}
int handleDelayedEvents(tank *tank,EnemyTank *enemyTank){
    // timer_increment();
    handleDelayedShooting(tank);
    handleDelayedEnemyShooting(enemyTank);
    
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
