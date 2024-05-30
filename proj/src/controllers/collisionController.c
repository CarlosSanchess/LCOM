#include "collisionController.h"

bool equalPosition(position pos1, position pos2){
    if(pos1.x == pos2.x && pos1.y == pos2.y){
        return true;
    }
    return false;
}
