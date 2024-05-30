#include "obstacle.h"


Obstacle* create_obstacle(int x1, int x2, int y1, int y2) {
    Obstacle* obs = (Obstacle*)malloc(sizeof(Obstacle));
    if (!obs) {
        return NULL;
    }
    obs->x1 = x1;
    obs->x2 = x2;
    obs->y1 = y1;
    obs->y2 = y2;
    return obs;
}

int add_obstacle(Obstacle** obstacleArray, size_t *numBuilts, int x1, int x2, int y1, int y2) {
    if (!obstacleArray) {
        return 1;
    }
    printf("%d \n ", *numBuilts);
    obstacleArray = (Obstacle**)realloc(obstacleArray, sizeof(Obstacle*) * (*numBuilts + 1));
    if (!obstacleArray) {
        return 1;
    }
    
    Obstacle* newObstacle = create_obstacle(x1, x2, y1, y2);
    if (!newObstacle) {
        return 1;
    }
    (obstacleArray)[*numBuilts] = newObstacle;
    (*numBuilts)++;
    
    return 0;
}

Obstacle** create_obstacle_array() {
    Obstacle** obsArray = (Obstacle**)malloc(sizeof(Obstacle*));
    if (!obsArray) {
        return NULL;
    }
    return obsArray;
}
