#ifndef __TIMER_CONTROLLER__
#define __TIMER_CONTROLLER__

#include "utils/utilsFunctions.h"
#include "../Models/mouse.h"
#include "../Models/arena.h"

#define SHOOTD 120 //2 seg between shoot
#define DRAWD 600//3 seg between draw
#define BUILDD 60 //1 seg 
#define BOMBD 40

static unsigned int timerCounter = 0; 

void timer_increment();

int handleDelayedEvents(Arena* arena, MouseInfo* mouseInfo);
int handleDelayedShooting(tank *tank);
void handleDelayedMouse(MouseInfo* mouseInfo);
void handleDelayedBuildings(Obstacle** obstacles, size_t numObstacles);
int handleDelayedEnemyShooting(EnemyTank *enemyTank);
void handleDelayedBomb(Arena* arena);

#endif
