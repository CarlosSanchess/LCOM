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
int handleInterruptMouse(State *gameState, Menu *menu, MouseInfo *mouseInfo){
    
    getPositionMouse(mouseInfo);

    if(*gameState == inMenu){
      processMenu(gameState, menu, mouseInfo);
    }
    if(*gameState == inGame){

    }
    return 0;
}

void getPositionMouse(MouseInfo *mouseInfo){
    mouse_ih();
    mouse_packet();

    if(mouseInfo->mousePosition.x + mouse_byte_packet.delta_x < 0 && !mouse_byte_packet.x_ov){
      mouseInfo->mousePosition.x = 0;
    }
    else if(mouseInfo->mousePosition.x + mouse_byte_packet.delta_x > 1152 && !mouse_byte_packet.x_ov){
      mouseInfo->mousePosition.x = 1152;
    }
    else if(!mouse_byte_packet.x_ov){
      mouseInfo->mousePosition.x+=mouse_byte_packet.delta_x;
    }

    if(mouseInfo->mousePosition.y-mouse_byte_packet.delta_y < 0 && !mouse_byte_packet.y_ov){
      mouseInfo->mousePosition.y = 0;
    }
    else if(mouseInfo->mousePosition.y-mouse_byte_packet.delta_y > 864 && !mouse_byte_packet.y_ov){
      mouseInfo->mousePosition.y = 864;
    }
    else if(!mouse_byte_packet.y_ov){
      mouseInfo->mousePosition.y-=mouse_byte_packet.delta_y;
    }
}

void processMenu(State *gameState, Menu *menu, MouseInfo *mouseInfo){

    if((mouseInfo->mousePosition.x > 327 && mouseInfo->mousePosition.x < 823) && (mouseInfo->mousePosition.y > 590 && mouseInfo->mousePosition.y < 673)){
        menu->selected = 0;
        if(mouse_byte_packet.lb){
            if(menu->selected == 0){
                *gameState = inGame;
            }
        }
     }

}