#include "mouseController.h"


void print_double(double n, bool x) {

  char str[100];
  if(x){
    sprintf(str, "EM X:%f\n", n);
    printf("EM X:%s ", str);
  }else{
    sprintf(str, "EM Y:%f\n", n);
    printf("EM Y:%s\n ========================================= \n ", str);
  }

}

//TODO ERROR HANDLING
//No need to pass mouse info
int handleInterruptMouse(State *gameState, Menu *menu, MouseInfo *mouseInfo){
    
    getPositionMouse(mouseInfo);

    if(*gameState == inMenu){
      processMenu(gameState, menu, mouseInfo);
    }
    if(*gameState == inGame){

    }
    return 0;
}

void getPositionMouse(MouseInfo *mouseInfo) {
    mouse_ih();
    mouse_packet();

    int smooth_dx = (int)(mouse_byte_packet.delta_x * MOUSE_SCALING_FACTOR);
    int smooth_dy = (int)(mouse_byte_packet.delta_y * MOUSE_SCALING_FACTOR);

    int cursor_size = 20; 

    if (!mouse_byte_packet.x_ov) {
        mouseInfo->mousePosition.x += smooth_dx;
        
        if (mouseInfo->mousePosition.x < cursor_size) {
            mouseInfo->mousePosition.x = cursor_size - 15; 
        } 
        else if (mouseInfo->mousePosition.x > SCREEN_WIDTH - cursor_size) {
            mouseInfo->mousePosition.x = SCREEN_WIDTH - cursor_size; 
        }
    } else {
        mouseInfo->mousePosition.x = cursor_size; 
    }

    if (!mouse_byte_packet.y_ov) {
        mouseInfo->mousePosition.y -= smooth_dy;
        
        if (mouseInfo->mousePosition.y < cursor_size) {
            mouseInfo->mousePosition.y = cursor_size - 15; 
        } 
        else if (mouseInfo->mousePosition.y > SCREEN_HEIGHT - cursor_size) {
            mouseInfo->mousePosition.y = SCREEN_HEIGHT - cursor_size; 
        }
    } else {
        mouseInfo->mousePosition.y = cursor_size; 
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
