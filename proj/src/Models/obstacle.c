#include "obstacle.h"


Obstacle* createObstacle(int x1, int x2, int y1, int y2){
    Obstacle* obs = (Obstacle*)malloc(sizeof(Obstacle));
    if(!obs){
        return NULL;
    }
    obs->x1 = x1;
    obs->x2 = x2;
    obs->y1 = y1;
    obs->y2 = y2;

    return obs;

}

int add_obstacle(Obstacle** obstacleArray, size_t index, int x1, int x2, int y1, int y2){
    if(!obstacleArray){
        return 1;
    }
    Obstacle** obstacle = (Obstacle**)realloc(obstacleArray, sizeof(Obstacle*) * index + 1);
    if(!obstacle){
        return 1;
    }
    obstacleArray[index] = createObstacle(x1, x2, y1, y2);
    return 0;
}
Obstacle** create_obstacle_array(){
    Obstacle** obs = (Obstacle**)malloc(sizeof(Obstacle*));
    if(!obs){
        return NULL;
    }
    return obs;
}
