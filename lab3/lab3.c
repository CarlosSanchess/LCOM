#include <lcom/lcf.h>
#include "i8042.h"
#include <lcom/lab3.h>

#include <stdbool.h>
#include <stdint.h>

extern uint8_t scanCode;
extern bool error;
extern int timer_counter;

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/lab3/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab3/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return 0;
}

//TIRAR CONTINUES E BREAKS
int(kbd_test_scan)() {
    uint8_t irq_set; 
    int ipc_status;
    message msg;
    uint8_t r;

    bool twoBytes;

    if(kbc_subscribe_int(&irq_set) != OK){
      fprintf(stderr,"Error in subscribing KBC interrupts.");
      return ERROR;
    }

    while(scanCode != BREAK_CODE(0x01)) { 
    /* Get a request message. */
    if ((r = driver_receive(ANY, &msg, &ipc_status)) != OK) { 
        printf("driver_receive failed with: %d", r);
        continue;
    }
    if (is_ipc_notify(ipc_status)) { /* received notification */
        switch (_ENDPOINT_P(msg.m_source)) {
            case HARDWARE: /* hardware interrupt notification */				
                 if (msg.m_notify.interrupts & irq_set){ /* subscribed interrupt */
                  if(error){
                    break;
                  }
                  kbc_ih();
                  if(scanCode)
                  if(scanCode == TWO_BYTE_LONG_SC){
                    twoBytes = 1;
                    continue;
                  }
                  if(twoBytes){
                    uint16_t* scanC = (uint16_t*)calloc(1,sizeof(uint16_t));
                    uint8_t aux = 0xE0;
                    if(scanC){
                      break;
                    }
                    memcpy(scanC,&aux,sizeof(uint8_t));
                    memcpy((uint8_t*)scanC + sizeof(uint8_t), &scanCode, sizeof(uint8_t));
                    kbd_print_scancode(!(scanCode & BIT(7)), sizeof(scanC), (uint8_t*)scanC);  

                    free(scanC);
                    twoBytes = 0;
                  }
                  kbd_print_scancode(!(scanCode & BIT(7)), sizeof(scanCode), &scanCode);
                }
                break;
            default:
                break; /* no other notifications expected: do nothing */	
        }
    } else { /* received a standard message, not a notification */
        /* no standard messages expected: do nothing */
    }
  }

    if(kbc_unsubscribe_int() != OK){
      fprintf(stderr,"Error in unsubcribing KBC interrupts.");
      return ERROR;
    }
  
  return ERROR;
}

//Revert lcf disable interrupts
int(kbd_test_poll)() {

  bool twoBytes;
  uint8_t twoB[2];
 // uint8_t irq_set; 
 // uint8_t kbc_Command; 
  while(scanCode != BREAK_CODE(0x01)){
    if(ready_to_poll()){
      kbc_ih();
      if(scanCode)
        if(scanCode == TWO_BYTE_LONG_SC){
          twoBytes = 1;
          continue;
        }
        if(twoBytes){
          twoB[0] = 0xE0;
          twoB[1] = scanCode;
          kbd_print_scancode(!(scanCode & BIT(7)), sizeof(twoBytes), twoB);

          // uint16_t* scanC = (uint16_t*)calloc(1,sizeof(uint16_t));
          // uint8_t aux = 0xE0;
          // if(scanC){
          //   break;
          // }
          // memcpy(scanC,&aux,sizeof(uint8_t));
          // memcpy((uint8_t*)scanC + sizeof(uint8_t), &scanCode, sizeof(uint8_t));
          // kbd_print_scancode(!(scanCode & BIT(7)), sizeof(scanC), (uint8_t*)scanC);  

          // free(scanC);
          twoBytes = 0;
        }
        kbd_print_scancode(!(scanCode & BIT(7)), sizeof(scanCode), &scanCode);
    }
  }
  // uint8_t kbc_Command = BIT(5) | BIT(4) | BIT(0);
  // sys_outb(INPUT_BUFFER, kbc_Command);
  // if(kbc_subscribe_int(&irq_set) != OK){
  //     fprintf(stderr,"Error in subscribing KBC interrupts.");
  //     return ERROR;
  //   }
  uint8_t kbc_status;
  if(util_sys_inb(0x64, &kbc_status) != 0){return 0;}



  return 1;
}

int(kbd_test_timed_scan)(uint8_t n) {

    int ipc_status;
    uint8_t irq_set_TIMER, irq_set_KBC;
    message msg;

    int seconds = 0;

    if (timer_subscribe_int(&irq_set_TIMER) != 0) return 1;
    if (kbc_subscribe_int(&irq_set_KBC) != 0) return 1;

    while (scanCode != 0x81 && seconds < n){

        if( driver_receive(ANY, &msg, &ipc_status) != 0 ){
            printf("Error");
            continue;
        }

        if(is_ipc_notify(ipc_status)) {
            switch(_ENDPOINT_P(msg.m_source)){
                 case HARDWARE:
                    if (msg.m_notify.interrupts & irq_set_KBC) {
                      kbc_ih();
                      if (scanCode == TWO_BYTE_LONG_SC) {
                        uint8_t twoB[2] = {0xE0, scanCode};
                        kbd_print_scancode(!(scanCode & BIT(7)), 2, twoB);
                      } else {
                        kbd_print_scancode(!(scanCode & BIT(7)), 1, &scanCode);
                      }
                      seconds = 0;
                      timer_counter = 0;
                    }
                    if (msg.m_notify.interrupts & irq_set_TIMER) {
                      timer_int_handler();
                      if (timer_counter % 60 == 0) seconds++;
                    }
            }
        }
    }

  if (timer_unsubscribe_int() != 0) return 1;
  if (kbc_unsubscribe_int() != 0) return 1;

  return 0;
}
