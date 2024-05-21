#include <lcom/lcf.h>
#include "dev_interface/devices/video_gr.h"
#include "dev_interface/devices/timer_kbc_mouse/mouse.h"

#include "controllers/kbController.h" 

#include "xpm/menu.xpm"
#include "xpm/mapa1.xpm"
#include "xpm/wrench_white.xpm"

#include "Models/state.h"
#include "dev_interface/sprites/sprite.h"




//game 
state currentState;

//kbc
uint8_t irq_kbc;

//mouse
uint8_t irq_mouse;
//timer


int safeExit();
int setUp();

int run(){


xpm_draw(menu, 0, 0);
xpm_draw_ignore(wrench_white, 50, 50, 0x0047bb);  
buffer_to_video_mem();
  
    message msg;
    int ipc_status;
    uint8_t r;

    while(1) { 
      if ((r = driver_receive(ANY, &msg, &ipc_status)) != OK) { 
          printf("driver_receive failed with: %d", r);
          continue;
      }
    if (is_ipc_notify(ipc_status)) { 
        switch (_ENDPOINT_P(msg.m_source)) {
            case HARDWARE: 			
                 if (msg.m_notify.interrupts & irq_kbc){  //kb interrupt
                  if(handleInterruptKBC(currentState) == 0){
                    safeExit();
                    return 0;
                  }
                }
                if(msg.m_notify.interrupts & irq_mouse){ //mouse interrupt
                  
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
  if (mouse_unsubscribe_int() != 0 || write_mouse(DISABLE_DATA_REPORT)){
      fprintf(stderr, "Failed to unsub mouse interrupts/ disable data report.");

    return 1;
  } 
  
  return 0;
}

int setUp(){
  currentState = inMenu;

  if(video_init(0x14C) != 0){
    return 1;
  }
  if(kbc_subscribe_int(&irq_kbc) != 0){
    return 1;
  }
  if(mouse_subscribe_int(&irq_mouse) != 0 || write_mouse(ENABLE_DATA_REPORT) != 0){ 
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
