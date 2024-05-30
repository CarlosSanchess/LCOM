#include "builderController.h"


int add_obstacleToArena(Arena* arena, int x1, int x2, int y1, int y2) {

    arena->builts = (Obstacle**)realloc(arena->builts, sizeof(Obstacle*) * (arena->numBuilts + 1));
    if (!arena->builts) {
        return 1;
    }
    
    Obstacle* newObstacle = createObstacle(x1, x2, y1, y2);
    if (!newObstacle) {
        return 1;
    }
    (arena->builts)[arena->numBuilts] = newObstacle;
    (arena->numBuilts)++;
    
    return 0;
}

int processBuilts(Arena *arena){
    for(size_t i = 0; i < arena->numBuilts; i++){
        if(arena->builts[i]->time <= 0){
            arena->builts = popObstacle(arena->builts, arena->numBuilts);
            arena->numBuilts--;
        } 
    }
    return 0;
}


