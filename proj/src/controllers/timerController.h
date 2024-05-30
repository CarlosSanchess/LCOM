#ifndef __TIMER_CONTROLLER__
#define __TIMER_CONTROLLER__

#include "utils/utilsFunctions.h"
#include "Models/Tank.h"
#include "Models/obstacle.h"
#include "Models/mouse.h"

#define SHOOTD 120 //3 seg between shoot
#define DRAWD 180 //4 seg between draw
#define BUILDD 60 //1 seg 

static unsigned int timerCounter = 0; 

void timer_increment();
int handleDelayedEvents(tank *tank, MouseInfo* mouseInfo, Obstacle** obstacles, size_t numObstacles);
int handleDelayedShooting(tank *tank);
void handleDelayedMouse(MouseInfo* mouseInfo);
void handleDelayedBuildings(Obstacle** obstacles, size_t numObstacles);
#endif
