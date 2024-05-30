#ifndef __BUILDER_CONTROLLER_
#define __BUILDER_CONTROLLER_

#include "Models/arena.h"
#include "Models/obstacle.h"


int add_obstacleToArena(Arena* arena, int x1, int x2, int y1, int y2);
int processBuilts(Arena *arena);

#endif

