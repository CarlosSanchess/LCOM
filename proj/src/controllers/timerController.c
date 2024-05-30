#include "timerController.h"

//todo same timer count for all
void timer_increment(){
    timerCounter++;
}
int handleDelayedEvents(tank *tank, MouseInfo* mouseInfo, Obstacle** obstacles, size_t numObstacles){
    // timer_increment();
    handleDelayedShooting(tank);
    handleDelayedMouse(mouseInfo);
    handleDelayedBuildings(obstacles, numObstacles);
    
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
        }
        delayBuildings = 0;
    }
}

