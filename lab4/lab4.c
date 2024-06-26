// IMPORTANT: you must include the following line in all your C files
#include <lcom/lcf.h>

#include <stdint.h>
#include <stdio.h>
#include "mouse.h"
#include "i8042.h"


extern struct packet mouse_byte_packet;
extern int mouse_index;
extern int timer_counter;

// Any header files included below this line should have been created by you

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need/ it]
  lcf_trace_calls("/home/lcom/labs/lab4/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab4/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}


int (mouse_test_packet)(uint32_t cnt) {
    int ipc_status;
    message msg;
    uint8_t mouse_mask;

    if (write_mouse(ENABLE_DATA_REPORT) != 0) return 1;
    if (mouse_subscribe_int(&mouse_mask) != 0) return 1;

    while (cnt) { 
      if (driver_receive(ANY, &msg, &ipc_status) != 0){
        printf("Error");
        continue;
      }

      if (is_ipc_notify(ipc_status)){
        switch(_ENDPOINT_P(msg.m_source)){
          case HARDWARE: 
            if (msg.m_notify.interrupts & mouse_mask){ 
              mouse_ih();                              
              if (mouse_index == 3) {                 
                mouse_packet();               
                mouse_print_packet(&mouse_byte_packet);      
                cnt--;
                mouse_index = 0;
              }
            }
            break;
        }
      }
    }
    

    if (mouse_unsubscribe_int() != 0) return 1;
  
    if (write_mouse(DISABLE_DATA_REPORT) != 0) return 1;

    return 0;
}

int (mouse_test_async)(uint8_t idle_time) {
    /* To be completed */
    printf("%s: under construction\n", __func__);
    return 1;
}

int (mouse_test_gesture)(uint8_t x_len, uint8_t tolerance) {
    /* To be completed */
    printf("%s: under construction\n", __func__);
    return 1;
}

int (mouse_test_remote)(uint16_t period, uint8_t cnt) {
    /* This year you need not implement this. */
    printf("%s(%u, %u): under construction\n", __func__, period, cnt);
    return 1;
}
