#ifndef __ARENA_CONTROLLER_
#define __ARENA_CONTROLLER_

#include "Models/arena.h"
#include "Models/state.h"
#include "tankController.h"
#include "enemyController.h"
#include "bulletController.h"
#include "controllers/gameController.h"

#define NEW_NUM_WAYPOINTS (NUM_WAYPOINTS + 10)

int processArena(State* currentState, Arena* arena);

#endif
