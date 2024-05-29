#ifndef __TIMER_CONTROLLER__
#define __TIMER_CONTROLLER__

#include "utils/utilsFunctions.h"
#include "Models/Tank.h"

#define SHOOTD 120 //3 seg between shoot

static unsigned int timerCounter = 0; 

void timer_increment();
int handleDelayedEvents(tank *tank);
int handleDelayedShooting(tank *tank);

#endif
