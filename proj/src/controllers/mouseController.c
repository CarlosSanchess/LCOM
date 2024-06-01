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
int handleInterruptMouse(State *gameState, Menu *menu, Arena* arena, MouseInfo *mouseInfo, HighScore score){
    
    getPositionMouse(mouseInfo);

    if(*gameState == inMenu){
      if(processMenu(gameState, menu, mouseInfo, score) != 0){
        return 1;
    }
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
        // if(mouseInfo->crossHair == 1){
            if(mouseInfo->mousePosition.x + smooth_dx > HAMMER_RIGHT){
            mouseInfo->mousePosition.x = HAMMER_RIGHT;
            return;
            }
            if(mouseInfo->mousePosition.x + smooth_dx < HAMMER_LEFT ){
                mouseInfo->mousePosition.x = HAMMER_LEFT;
            }else{
                mouseInfo->mousePosition.x += smooth_dx;
            }
        // }else{
        //     //Mouse For Menu
        // }   
    } else {
        mouseInfo->mousePosition.x = 50; 
    }


    if (!mouse_byte_packet.y_ov) {
        // if(mouseInfo->crossHair == 1){
            if(mouseInfo->mousePosition.y - smooth_dy > HAMMER_LOW){
                    mouseInfo->mousePosition.y = HAMMER_LOW;
                    return;
            }
            if(mouseInfo->mousePosition.y - smooth_dy < HAMMER_TOP){
                mouseInfo->mousePosition.y = HAMMER_TOP;
            }else{
                mouseInfo->mousePosition.y -= smooth_dy;
            }
        // }else{
        //     //MOUSE FOR MENU
        // }

    } else {
        mouseInfo->mousePosition.y = 50; 
    }
}

int processMenu(State *gameState, Menu *menu, MouseInfo *mouseInfo, HighScore score){

    if((mouseInfo->mousePosition.x > 318 && mouseInfo->mousePosition.x < 830) && (mouseInfo->mousePosition.y > 561 && mouseInfo->mousePosition.y < 639)){
        menu->selected = 0;
        if(mouse_byte_packet.lb){
            if(menu->selected == 0){
                *gameState = inGame;
                mouseInfo->crossHair = 1;
            }
        }
    }else if((mouseInfo->mousePosition.x > 355 && mouseInfo->mousePosition.x < 795) && (mouseInfo->mousePosition.y > 665 && mouseInfo->mousePosition.y < 737)){
        menu->selected = 1;
        if(mouse_byte_packet.lb){
            if(menu->selected == 1){
                *gameState = Multi;
                mouseInfo->crossHair = 1;
            }
        }
    }else if((mouseInfo->mousePosition.x > 725 && mouseInfo->mousePosition.x < 1107) && (mouseInfo->mousePosition.y > 33 && mouseInfo->mousePosition.y < 106)){
        if(mouse_byte_packet.lb){
            if(score.score > 0){
                 changeToHighScore(gameState, score);
            }
        }
    }else if((mouseInfo->mousePosition.x > 511 && mouseInfo->mousePosition.x < 639) && (mouseInfo->mousePosition.y > 762 && mouseInfo->mousePosition.y < 824)){
        menu->selected = 2;
        if(mouse_byte_packet.lb){
            if(menu-> selected == 3){
                return 2;
            }
        }
    }
    return 0;
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
