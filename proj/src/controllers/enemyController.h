#ifndef ENEMY_CONTROLLER_H
#define ENEMY_CONTROLLER_H

#include "tankController.h"
#include "Models/Tank.h"
#include "Models/arena.h"
#include "Models/Position.h"

#define WAYPOINT_MAX_DISTANCE 300
#define PATROL_SPEED 4
#define FOLLOW_SPEED 3
#define FOLLOW_THRESHOLD 200
#define MIN_DISTANCE_TO_OBSTACLE 10
#define NUM_WAYPOINTS 30
#define NUM_ATTEMPTS 10
#define WAYPOINT_TOLERANCE 5
#define MAX_WAYPOINTS 30
#define STUCK_THRESHOLD 3 
#define MOVE_DEVIATION 3

typedef struct {
    int x;
    int y;
} Waypoint;

Waypoint waypoints[NUM_WAYPOINTS];
extern bool waypointsGenerated; 

double calculateDistance(int x1, int y1, int x2, int y2);
bool canMoveEnemy(int newX, int newY, Obstacle obstacles[], int numObstacles);
void updateDirection(EnemyTank *enemy, int targetX, int targetY);
bool isValidWaypoint(int x, int y, Obstacle obstacles[], int numObstacles);
bool attemptMove(EnemyTank *enemy, int speed, int targetX, int targetY, Obstacle obstacles[], int numObstacles);
void followPlayer(EnemyTank *enemy, tank *player, Obstacle obstacles[], int numObstacles);
void updateEnemyTank(EnemyTank *enemy, tank *player, Waypoint waypoints[], int numWaypoints, Obstacle obstacles[], int numObstacles);
void patrol(EnemyTank *enemy, Waypoint waypoints[], int numWaypoints, Obstacle obstacles[], int numObstacles);

#endif
