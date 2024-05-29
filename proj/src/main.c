#include <lcom/lcf.h>
#include "dev_interface/devices/video_gr.h"

#include "controllers/mouseController.h"
#include "controllers/kbController.h" 
#include "controllers/arenaController.h"

#include "xpm/mapa1.xpm"

#include "Models/state.h"
#include "Models/menu.h"
#include "Models/mouse.h"

#include "Views/views.h"


//game 
State currentState;
Menu menu = {0, false, {{835, 596}, {660, 722}}}; 
MouseInfo mouseInfo = {.mousePosition = { 50, 50, 0}, 0};

//kbc
uint8_t irq_kbc;
//mouse
uint8_t irq_mouse;
//timer
uint8_t irq_timer;

int safeExit();
int setUp();

int run(){
    Arena *arena = createArena(1152,864,&mouseInfo);

    message msg;
    int ipc_status;
    uint8_t r;

    int aux = 0;

    while(1) { 
      if ((r = driver_receive(ANY, &msg, &ipc_status)) != OK) { 
          printf("driver_receive failed with: %d", r);
          continue;
      }
    if (is_ipc_notify(ipc_status)) { 
        switch (_ENDPOINT_P(msg.m_source)) {
            case HARDWARE: 
                 if (msg.m_notify.interrupts & irq_kbc){  //kb interrupt
                  if(handleInterruptKBC(&currentState, &menu, arena)){
                    safeExit();
                    return 0;
                  }
                }
                if (msg.m_notify.interrupts & irq_mouse){ //mouse interrupt
                  if(handleInterruptMouse(&currentState, &menu, &mouseInfo)){
                    safeExit();
                    return 0;
                  }
                }

                if(msg.m_notify.interrupts & irq_timer){ //timer interrupt
                  drawMouse(mouseInfo);
                  switch (currentState)
                  {
                  case inMenu:
                      drawMenu(menu);
                    break;
                  case inGame:
                    processArena(arena);

                    if(!aux){
                     xpm_draw_Background(mapa, 0, 0);
                    }
                    aux = 1;

                    drawArena(*arena);                  
                    break;
                  default:
                    break;
                  
                  }
                  buffer_to_video_mem();
                  restore_videoBuffer(); // current buffer = triple buffer 
                }
                 break;
            default:  
                break; 	
        }
      }
    }
  if(safeExit()){
    fprintf(stderr, "Failed to Exit");
  }
  return 0;
  
}
int safeExit(){
  if(kbc_unsubscribe_int() != 0){
    fprintf(stderr, "Failed to unsub kbc interrupts.");
    return 1;
  }
  if(vg_exit_graphics() != 0){
    fprintf(stderr, "Failed to exit graphics.");
    return 1;
  }

  if(timer_unsubscribe_int() != 0){
    fprintf(stderr, "Failed to unsub timer interrrupts.");
    return 1;  
  }

  if (mouse_unsubscribe_int() != 0){
       fprintf(stderr, "Failed to unsub mouse interrupts/ disable data report.");

     return 1;
   }

   if(write_mouse(DISABLE_DATA_REPORT) != 0){
    return 1;
   }
  
  return 0;
}

int setUp(){
  currentState = inMenu;

  if(video_init(0x14C) != 0){
    return 1;
  }

  xpm_draw_Background(menuXPM, 0, 0);
  xpm_draw_ignore(granade, menu.coord[0][0], menu.coord[0][1], 0x4ee44e);  
  buffer_to_video_mem();

  
  if(write_mouse(ENABLE_DATA_REPORT) != 0){
    return 1;
  }
  
  if(timer_set_frequency(0,20) != 0){
    fprintf(stderr, "set F");
    return 1;
  }

  if(kbc_subscribe_int(&irq_kbc) != 0){
    return 1;
  }

  if(timer_subscribe_int(&irq_timer) != 0){
    return 1;
  }

  if(mouse_subscribe_int(&irq_mouse) != 0){ 
     return 1;
  }

  return 0;
}
int main(int argc, char *argv[]) {

  lcf_set_language("EN-US");
  if (lcf_start(argc, argv)) return 1;
  lcf_cleanup();

  return 0;
}

int(proj_main_loop)(int argc, char *argv[]) {
  
  setUp();
  run();  

  return 0;
}
