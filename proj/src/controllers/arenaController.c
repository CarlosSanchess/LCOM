#include "arenaController.h"

Waypoint waypoints[NUM_WAYPOINTS] = {
    {890, 170}, {1089, 774}, {840, 439}, {691, 16}, {388, 101},
    {300, 431}, {80, 558}, {421, 780}, {700, 200}, {100, 300},
    {900, 500}, {600, 700}, {500, 50}, {200, 600}, {800, 100},
    {400, 400}, {1000, 800}, {300, 200}, {50, 750}, {500, 350},
    {800, 600}, {600, 250}, {230, 800}, {950, 200}, {300, 600},
    {150, 400}, {700, 600}, {400, 150}, {900, 700}, {50, 50}
};

bool waypointsGenerated = false;
Waypoint combinedWaypoints[NEW_NUM_WAYPOINTS];

int processArena(State* currentState, Arena* arena) {
    if(arena->endGame){
        changeToMenu(currentState, arena);
        return 0;
    }
    
    if (!waypointsGenerated){
        Waypoint newWaypoints[10];
        generateWaypoints(newWaypoints, 10);

        memcpy(combinedWaypoints, waypoints, sizeof(waypoints));
        memcpy(combinedWaypoints + NUM_WAYPOINTS, newWaypoints, sizeof(newWaypoints));
        waypointsGenerated = true;
    }

    if (processTank(arena->tank, arena->obstacles, NUM_OBSTACLES) != 0) {
        return 1;
    }

    if(processBullets(arena)){return 1;}
    if(processBuilts(arena)){return 1;}

    updateEnemyTank(arena,arena->enemyTank, arena->tank, combinedWaypoints, 40, arena->obstacles, NUM_OBSTACLES);

    return 0;
}
