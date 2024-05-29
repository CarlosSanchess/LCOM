#include "timerController.h"


void timer_increment(){
    timerCounter++;
}
int handleDelayedEvents(tank *tank){
    timer_increment();
    handleDelayedShooting(tank);
    
    return 0;
}

int handleDelayedShooting(tank *tank) {
    static int delayCounter = 0;
    if (!tank->canShoot) {
        delayCounter++;
        if (delayCounter >= SHOOTD) {
            tank->canShoot = true;
            delayCounter = 0; 
        }
    } else {
        delayCounter = 0; 
    }

    return 0;
}

