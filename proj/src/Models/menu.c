#include "menu.h"


int drawMenu(Menu menu){ //todo criar pasta view
    //xpm_draw(menuXPM, 0, 0);
    if(menu.selected == 0){
        xpm_draw_ignore(granade, menu.coord[0][0], menu.coord[0][1], GREEN_SCREEN);  
    }
    if(menu.selected == 1){
        xpm_draw_ignore(granade, menu.coord[1][0], menu.coord[1][1], GREEN_SCREEN);  
    }
    buffer_to_video_mem();
    return 0;
}
