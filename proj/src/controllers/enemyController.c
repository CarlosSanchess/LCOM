#include "enemyController.h"

void moveEnemyTank(tank* enemy, tank* player, Obstacle obstacles[], int numObstacles) {
    double angleToPlayer = atan2(player->position.y - enemy->position.y, player->position.x - enemy->position.x);
    double angleDifference = angleToPlayer - (enemy->position.deg * M_PI / 180.0);

    if (angleDifference > M_PI) {
        angleDifference -= 2 * M_PI;
    } else if (angleDifference < -M_PI) {
        angleDifference += 2 * M_PI;
    }

    if (angleDifference > 0.1) {
        enemy->wantToRotate += 10;
        enemy->direction = RIGHT;
    } else if (angleDifference < -0.1) {
        enemy->wantToRotate += 10;
        enemy->direction = LEFT;
    } else {
        int newX = enemy->position.x + (int)(enemy->speed * cos(enemy->position.deg * M_PI / 180.0));
        int newY = enemy->position.y + (int)(enemy->speed * sin(enemy->position.deg * M_PI / 180.0));
        if (canMove(newX, newY, obstacles, numObstacles)) {
            enemy->wantToMove = 6;
            enemy->direction = DOWN;
        } else {
            enemy->wantToRotate += 10;
            enemy->direction = RIGHT;
        }
    }
}

int processEnemyTank(tank* tank, Obstacle obstacles[], int numObstacles, Arena* arena) {
    int newY, newX;
    double radians;

    if (tank->wantToRotate >= 5) {
        switch (tank->direction) {
            case LEFT:
                tank->position.deg -= 10;
                tank->wantToRotate -= 5;
                if (tank->position.deg < 0) {
                    tank->position.deg += 360;
                }
                break;
            case RIGHT:
                tank->position.deg += 10;
                tank->wantToRotate -= 5;
                if (tank->position.deg >= 360) {
                    tank->position.deg -= 360;
                }
                break;
            default:
                break;
        }
    }

    if (tank->wantToMove >= 2) {
        radians = (tank->position.deg - 90) * (M_PI / 180.0);

        switch (tank->direction) {
            case UP:
                newX = tank->position.x - (int)(tank->speed * 2 * cos(radians));
                newY = tank->position.y - (int)(tank->speed * 2 * sin(radians));
                if (canMove(newX, newY, obstacles, NUM_OBSTACLES)) {
                    tank->position.x = newX;
                    tank->position.y = newY;
                }
                tank->wantToMove -= 2;
                break;
            case DOWN:
                newX = tank->position.x + (int)(tank->speed * 2 * cos(radians));
                newY = tank->position.y + (int)(tank->speed * 2 * sin(radians));
                if (canMove(newX, newY, obstacles, NUM_OBSTACLES)) {
                    tank->position.x = newX;
                    tank->position.y = newY;
                }
                tank->wantToMove -= 2;
                break;
            default:
                break;
        }
    }
    return 0;
}
