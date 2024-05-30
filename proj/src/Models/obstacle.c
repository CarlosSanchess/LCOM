#include "obstacle.h"


Obstacle* createObstacle(int x1, int x2, int y1, int y2){    
    Obstacle* obs = (Obstacle*)malloc(sizeof(Obstacle));
    if (!obs) {
        return NULL;
    }
    obs->x1 = x1;
    obs->x2 = x2;
    obs->y1 = y1;
    obs->y2 = y2;
    obs->time = 10;
    return obs;
}


Obstacle** create_obstacle_array() {
    Obstacle** obsArray = (Obstacle**)malloc(sizeof(Obstacle*));
    if (!obsArray) {
        return NULL;
    }
    return obsArray;
}

Obstacle** popObstacle(Obstacle** array, size_t numObstacles) {
    if (numObstacles <= 0) {
        return NULL;
    }
    Obstacle** temp = (Obstacle**)malloc((numObstacles - 1) * sizeof(Obstacle*));
    if (!temp) {
        return NULL; 
    }

    memcpy(temp, array, (numObstacles - 1) * sizeof(Obstacle*));
    

    free(array[numObstacles - 1]); 
    free(array);
    array = NULL;

    return temp;
}

