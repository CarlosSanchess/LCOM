#include <lcom/lcf.h>
#include "dev_interface/devices/video_gr.h"
#include "dev_interface/devices/timer_kbc_mouse/mouse.h"
#include "dev_interface/devices/timer_kbc_mouse/kbc.h"

#include "xpm/cursor.xpm"
#include "xpm/menu.xpm"
#include "dev_interface/sprites/sprite.h"

//kbc
extern uint8_t scanCode;

uint8_t irq_kbc;


int safeExit();

int test(){
  video_init(0x14C);

  xpm_draw(menu, 0, 0);

  xpm_draw(handCursor_xpm, 50, 50);

  buffer_to_video_mem();
  
    message msg;
    int ipc_status;
    uint8_t r;

      kbc_subscribe_int(&irq_kbc);
    while(1) { 
      if ((r = driver_receive(ANY, &msg, &ipc_status)) != OK) { 
          printf("driver_receive failed with: %d", r);
          continue;
      }
    if (is_ipc_notify(ipc_status)) { 
        switch (_ENDPOINT_P(msg.m_source)) {
            case HARDWARE: 			
                 if (msg.m_notify.interrupts & irq_kbc){  //kb interrup
                  kbc_ih();
                  if(scanCode == BREAK_CODE(0x01))
                  {
                    safeExit();
                    return 0;
                  }
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
    return 1;
  }
  if(vg_exit_graphics() != 0){
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
    

  test();  

  return 0;
}
