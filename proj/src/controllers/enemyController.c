#include "enemyController.h"
 
double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool canMoveEnemy(int newX, int newY, Obstacle obstacles[], int numObstacles) {
    if (newX < 0 || newX >= MAP_WIDTH - TANK_WIDTH || newY < 0 || newY >= MAP_HEIGHT - TANK_HEIGHT) {
        return false;
    }

    for (int i = 0; i < numObstacles; i++) {
        if (newX < obstacles[i].x2 && newX + TANK_WIDTH > obstacles[i].x1 &&
            newY < obstacles[i].y2 && newY + TANK_HEIGHT > obstacles[i].y1) {
            return false;
        }
    }
    return true;
}

void updateDirection(EnemyTank *enemy, int targetX, int targetY) {
    double angle = atan2(targetY - enemy->position.y, targetX - enemy->position.x) * 180 / M_PI;
    angle += 270;

    if (angle < 0) {
        angle += 360;
    }
    angle = fmod(angle, 360);

    enemy->position.deg = (int)angle;

    if (enemy->position.deg >= 45 && enemy->position.deg < 135) {
        enemy->direction = 0;
    } else if (enemy->position.deg >= 135 && enemy->position.deg < 225) {
        enemy->direction = 1;
    } else if (enemy->position.deg >= 225 && enemy->position.deg < 315) {
        enemy->direction = 2;
    } else {
        enemy->direction = 3;
    }
}

void updateTankDirection(EnemyTank *enemy, double angle) {
    double newAngle = angle * 180 / M_PI;
    newAngle += 270;
    if (newAngle < 0) {
        newAngle += 360;
    }
    newAngle = fmod(newAngle, 360);

    enemy->position.deg = (int)newAngle;
    if (enemy->position.deg >= 45 && enemy->position.deg < 135) {
        enemy->direction = 0; 
    } else if (enemy->position.deg >= 135 && enemy->position.deg < 225) {
        enemy->direction = 1; 
    } else if (enemy->position.deg >= 225 && enemy->position.deg < 315) {
        enemy->direction = 2; 
    } else {
        enemy->direction = 3; 
    }
}

bool attemptMove(EnemyTank *enemy, int speed, int targetX, int targetY, Obstacle obstacles[], int numObstacles, bool withinThreshold) {
    double angle = atan2(targetY - enemy->position.y, targetX - enemy->position.x);
    int newX = enemy->position.x + (int)(speed * cos(angle));
    int newY = enemy->position.y + (int)(speed * sin(angle));

    if (canMoveEnemy(newX, newY, obstacles, numObstacles)) {
        enemy->position.x = newX;
        enemy->position.y = newY;
        
        if (!withinThreshold) {
            updateTankDirection(enemy, angle);
        }
        
        return true;
    }
    return false;
}

void followPlayer(EnemyTank *enemy, tank *player, Obstacle obstacles[], int numObstacles) {
    attemptMove(enemy, FOLLOW_SPEED, player->position.x, player->position.y, obstacles, numObstacles, true); 
}

void shootAtPlayer(Arena *arena) {
    updateDirection(arena->enemyTank, arena->tank->position.x, arena->tank->position.y);
    if(arena->enemyTank->canShoot){
        addBulletToArena(arena,RED_TANK);
        arena->enemyTank->canShoot = false;
    }
}

void generateWaypoints(Waypoint waypoints[], int numWaypoints) {
    srand(time(NULL));
    for (int i = 0; i < numWaypoints; i++) {
        waypoints[i].x = rand() % MAP_WIDTH;
        waypoints[i].y = rand() % MAP_HEIGHT;
    }
}

void moveTowardsWaypointWithDeviation(EnemyTank *enemy, Waypoint targetWaypoint, Obstacle obstacles[], int numObstacles) {
    double angleToWaypoint = atan2(targetWaypoint.y - enemy->position.y, targetWaypoint.x - enemy->position.x);
    int newX = enemy->position.x + (int)(2 * cos(angleToWaypoint));
    int newY = enemy->position.y + (int)(2 * sin(angleToWaypoint));

    if (!canMoveEnemy(newX, newY, obstacles, numObstacles)) {
            double minDistance = 1e6;
            int closestWaypointIndex = 0;
            for (int i = 0; i < NUM_WAYPOINTS; i++) {
                double distance = calculateDistance(enemy->position.x, enemy->position.y, waypoints[i].x, waypoints[i].y);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestWaypointIndex = i;
                }
            }
            enemy->currentWaypoint = closestWaypointIndex;
            targetWaypoint = waypoints[closestWaypointIndex];
    }
    attemptMove(enemy, 2, targetWaypoint.x, targetWaypoint.y, obstacles, numObstacles,false);
}

bool hasReachedWaypoint(EnemyTank *enemy, Waypoint waypoint) {
    double distance = calculateDistance(enemy->position.x, enemy->position.y, waypoint.x, waypoint.y);
    return distance <= WAYPOINT_TOLERANCE;
}

void updateEnemyTank(Arena *arena, EnemyTank *enemy, tank *player, Waypoint waypoints[], int numWaypoints, Obstacle obstacles[], int numObstacles) {
    static bool visitedWaypoints[40] = { false };
    static int visitedCount = 0;
    static int stuckCounter = 0;
    static int positionHistory[10][2] = { {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} };
    static int historyIndex = 0;
    static int closestWaypointIndex = -1;

    double distanceToPlayer = calculateDistance(enemy->position.x, enemy->position.y, player->position.x, player->position.y);
    bool followingPlayer = (distanceToPlayer <= FOLLOW_THRESHOLD);

    if (followingPlayer) {
        stuckCounter = 0;
        if (distanceToPlayer <= FOLLOW_THRESHOLD - 10) {
            shootAtPlayer(arena);
        } else {
            followPlayer(enemy, player, obstacles, numObstacles);
        }
    } else {
        if (closestWaypointIndex == -1 && !visitedWaypoints[enemy->currentWaypoint]) {
            double minDistance = 1e6;
            closestWaypointIndex = -1;
            for (int i = 0; i < numWaypoints; i++) {
                if (!visitedWaypoints[i]) {
                    double distance = calculateDistance(enemy->position.x, enemy->position.y, waypoints[i].x, waypoints[i].y);
                    if (distance < minDistance) {
                        minDistance = distance;
                        closestWaypointIndex = i;
                        enemy->currentWaypoint = i;
                    }
                }
            }
        }


        if (closestWaypointIndex != -1 && !visitedWaypoints[closestWaypointIndex]) {
            moveTowardsWaypointWithDeviation(enemy, waypoints[closestWaypointIndex], obstacles, numObstacles);
            if (hasReachedWaypoint(enemy, waypoints[closestWaypointIndex])) {
                visitedWaypoints[closestWaypointIndex] = true;
                visitedCount++;

                if (visitedCount >= numWaypoints) {
                    for (int i = 0; i < numWaypoints; i++) {
                        visitedWaypoints[i] = false;
                    }
                    visitedCount = 0;
                }
            }
        }

        positionHistory[historyIndex][0] = enemy->position.x;
        positionHistory[historyIndex][1] = enemy->position.y;
        historyIndex = (historyIndex + 1) % 10;

        if ((abs(enemy->position.x - positionHistory[historyIndex][0]) <= 2) && (abs(enemy->position.y - positionHistory[historyIndex][1]) <= 2)) {
            stuckCounter++;
        } else {
            stuckCounter = 0;
        }

        if (stuckCounter >= 2) {
            stuckCounter = 0;
            visitedWaypoints[closestWaypointIndex] = true;
            visitedCount++;

            if (visitedCount >= numWaypoints) {
                for (int i = 0; i < numWaypoints; i++) {
                    visitedWaypoints[i] = false;
                }
                visitedCount = 0;
            }

            double minDistance = 1e6;
            closestWaypointIndex = -1;
            for (int i = 0; i < numWaypoints; i++) {
                if (!visitedWaypoints[i]) {
                    double distance = calculateDistance(enemy->position.x, enemy->position.y, waypoints[i].x, waypoints[i].y);
                    if (distance < minDistance) {
                        minDistance = distance;
                        closestWaypointIndex = i;
                    }
                }
            }
            enemy->currentWaypoint = closestWaypointIndex;
            moveTowardsWaypointWithDeviation(enemy, waypoints[closestWaypointIndex], obstacles, numObstacles);
        }
    }
}

