#include "mouseController.h"


void print_double(double n) {

  char str[100];
    sprintf(str, "EM X:%f\n", n);
    printf("EM X:%s ", str);
    sprintf(str, "EM Y:%f\n", n);
    printf("EM Y:%s\n ========================================= \n ", str);
}

//TODO ERROR HANDLING
//No need to pass mouse info
int handleInterruptMouse(State *gameState, Menu *menu, Arena* arena, MouseInfo *mouseInfo){
    
    getPositionMouse(mouseInfo);

    if(*gameState == inMenu){
      processMenu(gameState, menu, mouseInfo);
    }
    if(*gameState == inGame){
        if(mouseInfo->canBuild){processBuild(arena,mouseInfo);}
    }
    return 0;
}

void getPositionMouse(MouseInfo *mouseInfo) {
    mouse_ih();
    mouse_packet();

    int smooth_dx = (int)(mouse_byte_packet.delta_x * MOUSE_SCALING_FACTOR);
    int smooth_dy = (int)(mouse_byte_packet.delta_y * MOUSE_SCALING_FACTOR);


    if (!mouse_byte_packet.x_ov) {
        if(mouseInfo->crossHair == 1){
            if(mouseInfo->mousePosition.x + smooth_dx > HAMMER_RIGHT){
            mouseInfo->mousePosition.x = HAMMER_RIGHT;
            return;
            }
            if(mouseInfo->mousePosition.x + smooth_dx < HAMMER_LEFT ){
                mouseInfo->mousePosition.x = HAMMER_LEFT;
            }else{
                mouseInfo->mousePosition.x += smooth_dx;
            }
        }else{
            //Mouse For Menu
        }   
    } else {
        mouseInfo->mousePosition.x = 50; 
    }


    if (!mouse_byte_packet.y_ov) {
        if(mouseInfo->crossHair == 1){
            if(mouseInfo->mousePosition.y - smooth_dy > HAMMER_LOW){
                    mouseInfo->mousePosition.y = HAMMER_LOW;
                    return;
            }
            if(mouseInfo->mousePosition.y - smooth_dy < HAMMER_TOP){
                mouseInfo->mousePosition.y = HAMMER_TOP;
            }else{
                mouseInfo->mousePosition.y -= smooth_dy;
            }
        }else{
            //MOUSE FOR MENU
        }

    } else {
        mouseInfo->mousePosition.y = 50; 
    }
}

void processMenu(State *gameState, Menu *menu, MouseInfo *mouseInfo){

    if((mouseInfo->mousePosition.x > 327 && mouseInfo->mousePosition.x < 823) && (mouseInfo->mousePosition.y > 590 && mouseInfo->mousePosition.y < 673)){
        menu->selected = 0;
        if(mouse_byte_packet.lb){
            if(menu->selected == 0){
                *gameState = inGame;
                mouseInfo->crossHair = 1;
            }
        }
     }

}

int processBuild(Arena* arena, MouseInfo* mouseInfo){
    if((mouseInfo->mousePosition.x > 0 && mouseInfo->mousePosition.x < MAP_WIDTH) && (mouseInfo->mousePosition.y > 0 && mouseInfo->mousePosition.y < MAP_HEIGHT)){
        if(mouse_byte_packet.rb){
            add_obstacleToArena(arena, mouseInfo->mousePosition.x,  mouseInfo->mousePosition.x + 50,  mouseInfo->mousePosition.y, mouseInfo->mousePosition.y + 50);
            mouseInfo->canBuild = false;
        }
    }
    return 0;
}
