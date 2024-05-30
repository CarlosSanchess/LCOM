#ifndef __OBSTACLE__
#define __OBSTACLE__

#include <lcom/lcf.h>

#define TIME 20

typedef struct {
    int x1, x2;
    int y1, y2;
    uint8_t time;
    bool draw;
} Obstacle;

Obstacle* createObstacle(int x1, int x2, int y1, int y2);
Obstacle** create_obstacle_array();
Obstacle** popObstacle(Obstacle** array, size_t numObstacles);

#endif

