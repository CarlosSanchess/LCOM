/**
 * @file enemyController.h
 * @brief Defines functions and constants for enemy tanks "Intelligent" movement.
 * 
 * In order to make the enemy movement more interesting, the enemy tanks patrol certain waypoints looking for the player.
 * Some of them are hard-coded the other waypoints are randomly generated.
 * This file represents our effort to make the movement seem less predictabls and more challenging.
 */

#ifndef ENEMY_CONTROLLER_H
#define ENEMY_CONTROLLER_H

#include "tankController.h"
#include "bulletController.h"
#include "Models/Tank.h"
#include "Models/arena.h"
#include "Models/Position.h"

/** Maximum distance for waypoints */
#define WAYPOINT_MAX_DISTANCE 300

/** Speed of enemy tanks while patrolling */
#define PATROL_SPEED 4

/** Speed of enemy tanks while following the player */
#define FOLLOW_SPEED 3

/** Threshold distance for following the player */
#define FOLLOW_THRESHOLD 200

/** Minimum distance to avoid obstacles */
#define MIN_DISTANCE_TO_OBSTACLE 5

/** Number of waypoints for enemy navigation */
#define NUM_WAYPOINTS 30

/** Number of attempts to find a valid movement path */
#define NUM_ATTEMPTS 10

/** Tolerance distance for reaching waypoints */
#define WAYPOINT_TOLERANCE 0

/** Maximum number of waypoints */
#define MAX_WAYPOINTS 30

/** Threshold for considering an enemy tank as stuck */
#define STUCK_THRESHOLD 5

/** Deviation allowed in movement */
#define MOVE_DEVIATION 3

/**
 * @brief Structure to represent a waypoint.
 */
typedef struct {
    int x; /**< X coordinate of the waypoint */
    int y; /**< Y coordinate of the waypoint */
} Waypoint;

/** Array of waypoints for enemy navigation */
Waypoint waypoints[NUM_WAYPOINTS];

/** Flag indicating if waypoints have been generated */
extern bool waypointsGenerated;

/**
 * @brief Calculates the distance between two points.
 * 
 * @param x1 X coordinate of the first point.
 * @param y1 Y coordinate of the first point.
 * @param x2 X coordinate of the second point.
 * @param y2 Y coordinate of the second point.
 * @return double The distance between the two points.
 */
double calculateDistance(int x1, int y1, int x2, int y2);

/**
 * @brief Checks if an enemy tank can move to a new position.
 * 
 * @param newX New X coordinate.
 * @param newY New Y coordinate.
 * @param obstacles Array of obstacles.
 * @param numObstacles Number of obstacles.
 * @return bool True if the enemy tank can move to the new position, false otherwise.
 */
bool canMoveEnemy(int newX, int newY, Obstacle obstacles[], int numObstacles);

/**
 * @brief Updates the direction of an enemy tank towards a target.
 * 
 * @param enemy Pointer to the enemy tank.
 * @param targetX X coordinate of the target.
 * @param targetY Y coordinate of the target.
 */
void updateDirection(EnemyTank *enemy, int targetX, int targetY);

/**
 * @brief Updates the direction of an enemy tank based on an angle rotating it.
 * 
 * @param enemy Pointer to the enemy tank.
 * @param angle The angle to update the direction.
 */
void updateTankDirection(EnemyTank *enemy, double angle);

/**
 * @brief Attempts to move an enemy tank towards a target.
 * 
 * @param enemy Pointer to the enemy tank.
 * @param speed Speed of the enemy tank.
 * @param targetX X coordinate of the target.
 * @param targetY Y coordinate of the target.
 * @param obstacles Array of obstacles.
 * @param numObstacles Number of obstacles.
 * @param withinThreshold Flag indicating if the movement is within threshold.
 * @return bool True if the enemy tank can move, false otherwise.
 */
bool attemptMove(EnemyTank *enemy, int speed, int targetX, int targetY, Obstacle obstacles[], int numObstacles, bool withinThreshold);

/**
 * @brief Makes an enemy tank follow the player.
 * 
 * @param enemy Pointer to the enemy tank.
 * @param player Pointer to the player's tank.
 * @param obstacles Array of obstacles.
 * @param numObstacles Number of obstacles.
 */
void followPlayer(EnemyTank *enemy, tank *player, Obstacle obstacles[], int numObstacles);

/**
 * @brief Makes an enemy tank shoot at the player.
 * 
 * @param arena Pointer to the arena structure.
 */
void shootAtPlayer(Arena *arena);

/**
 * @brief Generates random waypoints for enemy navigation providing a certain randomness on each subsequent gameplay.
 * 
 * @param waypoints Array of waypoints to generate.
 * @param numWaypoints Number of waypoints to generate.
 */
void generateWaypoints(Waypoint waypoints[], int numWaypoints);

/**
 * @brief Moves an enemy tank towards a waypoint with deviation also providing some randomness.
 * 
 * @param enemy Pointer to the enemy tank.
 * @param targetWaypoint The target waypoint.
 * @param obstacles Array of obstacles.
 * @param numObstacles Number of obstacles.
 */
void moveTowardsWaypointWithDeviation(EnemyTank *enemy, Waypoint targetWaypoint, Obstacle obstacles[], int numObstacles);

/**
 * @brief Checks if an enemy tank has reached a waypoint.
 * 
 * @param enemy Pointer to the enemy tank.
 * @param waypoint The waypoint to check.
 * @return bool True if the enemy tank has reached the waypoint, false otherwise.
 */
bool hasReachedWaypoint(EnemyTank *enemy, Waypoint waypoint);

/**
 * @brief Updates the state of an enemy tank.
 * 
 * @param arena Pointer to the arena structure.
 * @param enemy Pointer to the enemy tank.
 * @param player Pointer to the player's tank.
 * @param waypoints Array of waypoints.
 * @param numWaypoints Number of waypoints.
 * @param obstacles Array of obstacles.
 * @param numObstacles Number of obstacles.
 */
void updateEnemyTank(Arena *arena, EnemyTank *enemy, tank *player, Waypoint waypoints[], int numWaypoints, Obstacle obstacles[], int numObstacles);

#endif // ENEMY_CONTROLLER_H
