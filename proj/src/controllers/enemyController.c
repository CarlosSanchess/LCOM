#include "enemyController.h"
 
double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt((x2 - x1) * (x2 - y2) + (y2 - y1) * (y2 - y1));
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

bool attemptMove(EnemyTank *enemy, int speed, int targetX, int targetY, Obstacle obstacles[], int numObstacles) {
    double angle = atan2(targetY - enemy->position.y, targetX - enemy->position.x);
    int newX = enemy->position.x + (int)(speed * cos(angle));
    int newY = enemy->position.y + (int)(speed * sin(angle));

    if (canMoveEnemy(newX, newY, obstacles, numObstacles)) {
        enemy->position.x = newX;
        enemy->position.y = newY;
        return true;
    }
    return false;
}

bool attemptUnstuckMove(EnemyTank *enemy, int speed, Obstacle obstacles[], int numObstacles) {
    static const int directions[4][2] = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    for (int i = 0; i < 4; i++) {
        int newX = enemy->position.x + directions[i][0] * speed;
        int newY = enemy->position.y + directions[i][1] * speed;

        if (canMoveEnemy(newX, newY, obstacles, numObstacles)) {
            enemy->position.x = newX;
            enemy->position.y = newY;
            return true;
        }
    }
    return false;
}

void followPlayer(EnemyTank *enemy, tank *player, Obstacle obstacles[], int numObstacles) {
    updateDirection(enemy, player->position.x, player->position.y);
    if (!attemptMove(enemy, FOLLOW_SPEED, player->position.x, player->position.y, obstacles, numObstacles)) {
        attemptUnstuckMove(enemy, FOLLOW_SPEED, obstacles, numObstacles);
    }
}

void shootAtPlayer(EnemyTank *enemy, tank *player) {
    updateDirection(enemy, player->position.x, player->position.y);
}

void generateRandomWaypoints(Waypoint waypoints[], int numWaypoints) {
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
        if (!attemptUnstuckMove(enemy, 2, obstacles, numObstacles)) {
            double minDistance = DBL_MAX;
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
    }

    attemptMove(enemy, 2, targetWaypoint.x, targetWaypoint.y, obstacles, numObstacles);
}

bool hasReachedWaypoint(EnemyTank *enemy, Waypoint waypoint) {
    double distance = calculateDistance(enemy->position.x, enemy->position.y, waypoint.x, waypoint.y);
    return distance <= WAYPOINT_TOLERANCE;
}

void updateEnemyTank(EnemyTank *enemy, tank *player, Waypoint waypoints[], int numWaypoints, Obstacle obstacles[], int numObstacles) {
    static bool visitedWaypoints[MAX_WAYPOINTS] = { false };
    static int visitedCount = 0;
    static int stuckCounter = 0;
    static int prevX = 0, prevY = 0;

    double distanceToPlayer = calculateDistance(enemy->position.x, enemy->position.y, player->position.x, player->position.y);
    bool followingPlayer = (distanceToPlayer <= FOLLOW_THRESHOLD);

    if (followingPlayer) {
        if (distanceToPlayer <= FOLLOW_THRESHOLD - 10) {
            shootAtPlayer(enemy, player);
        } else {
            followPlayer(enemy, player, obstacles, numObstacles);
        }
    } else {
        double minDistance = DBL_MAX;
        int closestWaypointIndex = -1;
        for (int i = 0; i < numWaypoints; i++) {
            if (!visitedWaypoints[i]) {
                double distance = calculateDistance(enemy->position.x, enemy->position.y, waypoints[i].x, waypoints[i].y);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestWaypointIndex = i;
                }
            }
        }

        if (closestWaypointIndex == -1) {
            for (int i = 0; i < numWaypoints; i++) {
                visitedWaypoints[i] = false;
            }
            visitedCount = 0;

            for (int i = 0; i < numWaypoints; i++) {
                double distance = calculateDistance(enemy->position.x, enemy->position.y, waypoints[i].x, waypoints[i].y);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestWaypointIndex = i;
                }
            }
        }

        Waypoint targetWaypoint = waypoints[closestWaypointIndex];

        moveTowardsWaypointWithDeviation(enemy, targetWaypoint, obstacles, numObstacles);

        if (hasReachedWaypoint(enemy, targetWaypoint)) {
            visitedWaypoints[closestWaypointIndex] = true;
            visitedCount++;

            minDistance = DBL_MAX;
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

            if (closestWaypointIndex == -1) {
                for (int i = 0; i < numWaypoints; i++) {
                    visitedWaypoints[i] = false;
                }
                visitedCount = 0;

                for (int i = 0; i < numWaypoints; i++) {
                    double distance = calculateDistance(enemy->position.x, enemy->position.y, waypoints[i].x, waypoints[i].y);
                    if (distance < minDistance) {
                        minDistance = distance;
                        closestWaypointIndex = i;
                    }
                }
            }

            targetWaypoint = waypoints[closestWaypointIndex];
        }

        moveTowardsWaypointWithDeviation(enemy, targetWaypoint, obstacles, numObstacles);
    }

    if (abs(enemy->position.x - prevX) < 2 && abs(enemy->position.y - prevY) < 2) {
        stuckCounter++;
    } else {
        stuckCounter = 0;
    }

    prevX = enemy->position.x;
    prevY = enemy->position.y;

    if (stuckCounter > STUCK_THRESHOLD) {
        attemptUnstuckMove(enemy, MOVE_DEVIATION, obstacles, numObstacles);
        stuckCounter = 0;
    }
}
