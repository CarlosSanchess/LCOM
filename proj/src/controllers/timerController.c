#include "timerController.h"


void timer_increment(){
    timerCounter++;
}
int handleDelayedEvents(tank *tank, MouseInfo* mouseInfo){
    // timer_increment();
    handleDelayedShooting(tank);
    handleDelayedMouse(mouseInfo);
    
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

