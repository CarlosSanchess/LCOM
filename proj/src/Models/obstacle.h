#ifndef __OBSTACLE__
#define __OBSTACLE__

#include <lcom/lcf.h>


typedef struct {
    int x1, x2;
    int y1, y2;
} Obstacle;

Obstacle* createObstacle(int x1, int x2, int y1, int y2);
Obstacle** create_obstacle_array();
int add_obstacle(Obstacle** obstacleArray, size_t *numBuilts, int x1, int x2, int y1, int y2);

#endif
