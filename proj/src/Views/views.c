#include "views.h"

int drawArena(Arena arena){
    drawBullets(arena);
    drawTank(arena.tank);
    drawEnemyTank(arena.enemyTank);
    drawBuilds(arena.builts, arena.numBuilts);

    return 0;
}

int drawTank(tank *tank) {
    xpm_draw_ignore_rot(tank_green, tank->position.x, tank->position.y, tank->position.deg, GREEN_SCREEN);
    return 0;
}

int drawEnemyTank(EnemyTank *tank) {
    xpm_draw_ignore_rot(tank_red, tank->position.x, tank->position.y, tank->position.deg, GREEN_SCREEN);
    return 0;
}

int drawBomb(int x, int y){
    xpm_draw_ignore(bomb, x, y, GREEN_SCREEN);
    return 0;
}

int drawMenu(Menu menu){ 
    if(menu.selected == 0){
        xpm_draw_ignore(granade, menu.coord[0][0], menu.coord[0][1], GREEN_SCREEN);  
    }
    if(menu.selected == 1){
        xpm_draw_ignore(granade, menu.coord[1][0], menu.coord[1][1], GREEN_SCREEN);  
    }
    return 0;
}

int drawMouse(MouseInfo mouse){
    if((mouse.mousePosition.x > 0 && mouse.mousePosition.x < 1152) && (mouse.mousePosition.y > 0 && mouse.mousePosition.y < 864)){
        if(mouse.crossHair == 0){
            if(xpm_draw_ignore(cursor, mouse.mousePosition.x, mouse.mousePosition.y, GREEN_SCREEN) != 0){
                return 1;
            }
        }else{
             if(xpm_draw_ignore_Hammer(martelo, mouse.mousePosition.x, mouse.mousePosition.y, GREEN_SCREEN, mouse.canBuild) != 0){
                return 1;
            }
        }
    }
    return 0;
}
int drawBullets(Arena arena){
    for(size_t i = 0; i < arena.numBullets; i++){
        drawBullet(*(arena.bullets[i]));
    }
    return 0;
}
int drawBullet(bullet b){
    xpm_draw_ignore_rot(bullet_xpm, b.position.x, b.position.y, b.position.deg, GREEN_SCREEN);
    return 0;
}

int drawBuilds(Obstacle** builds, size_t numBuilts){ //TODO char* to xpm_row_t
    for(size_t i = 0; i < numBuilts; i++){ 
        if(builds[i]->draw && builds[i]->time == 10){xpm_draw_ignore(block10, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 9) {xpm_draw_ignore(block9, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 8) {xpm_draw_ignore(block8, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 7) {xpm_draw_ignore(block7, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 6) {xpm_draw_ignore(block6, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 5) {xpm_draw_ignore(block5, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 4) {xpm_draw_ignore(block4, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 3) {xpm_draw_ignore(block3, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 2) {xpm_draw_ignore(block2, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}
        if(builds[i]->draw && builds[i]->time == 1) {xpm_draw_ignore(block1, builds[i]->x1, builds[i]->y1, GREEN_SCREEN);}                
    }
    return 0;
}
