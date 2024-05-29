#include "timerController.h"


void timer_increment(){
    timerCounter++;
}
int handleDelayedEvents(tank *tank){
    // timer_increment();
    handleDelayedShooting(tank);
    
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

