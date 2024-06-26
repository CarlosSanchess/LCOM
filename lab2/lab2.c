#include <lcom/lcf.h>
#include <lcom/lab2.h>

#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>
#include <errno.h>

extern unsigned int timer_counter;

int main(int argc, char *argv[]) {
  // sets the language of LCF messages (can be either EN-US or PT-PT)
  lcf_set_language("EN-US");

  // enables to log function invocations that are being "wrapped" by LCF
  // [comment this out if you don't want/need it]
  lcf_trace_calls("/home/lcom/labs/lab2/trace.txt");

  // enables to save the output of printf function calls on a file
  // [comment this out if you don't want/need it]
  lcf_log_output("/home/lcom/labs/lab2/output.txt");

  // handles control over to LCF
  // [LCF handles command line arguments and invokes the right function]
  if (lcf_start(argc, argv))
    return 1;

  // LCF clean up tasks
  // [must be the last statement before return]
  lcf_cleanup();

  return OK;
}

int(timer_test_read_config)(uint8_t timer, enum timer_status_field field) {
  uint8_t st;
  if(timer_get_conf(timer, &st) != OK){
    fprintf(stderr,"Timer_get_conf error");
    return 1;
  }
  if(timer_display_conf(timer,st,field) != OK){
    fprintf(stderr,"Timer_display_conf error");
    return 1;
  }

  return OK;
}

int(timer_test_time_base)(uint8_t timer, uint32_t freq) {
  
  if(timer_set_frequency(timer, freq) != OK) return 1;

  return OK;
}

int(timer_test_int)(uint8_t time) {
  
  int ipc_status;
  message msg;
  uint8_t irq_set; //hook_id
  uint8_t r;

  

  if(timer_subscribe_int(&irq_set) != OK){
    fprintf(stderr,"Error in ubscribing T0 interrupts.");
    return 1;
  }
  uint16_t aux = time * 60; // Time max for 60 hz == 1092 seg (Not possible, uint8_t time)
  while(timer_counter < aux) { 
    /* Get a request message. */
    if ((r = driver_receive(ANY, &msg, &ipc_status)) != OK) { 
        printf("driver_receive failed with: %d", r);
        continue;
    }
    if (is_ipc_notify(ipc_status)) { /* received notification */
        switch (_ENDPOINT_P(msg.m_source)) {
            case HARDWARE: /* hardware interrupt notification */				
                 if (msg.m_notify.interrupts & irq_set){ /* subscribed interrupt */ // Freq 60 
                  timer_int_handler();    
                  if(!(timer_counter % 60)){ // We dont want to modify counter value
                    timer_print_elapsed_time();
                    time--;
                  }
                }
                break;
            default:
                break; /* no other notifications expected: do nothing */	
        }
    } else { /* received a standard message, not a notification */
        /* no standard messages expected: do nothing */
    }
  }
  if(timer_unsubscribe_int() != OK){
    fprintf(stderr,"Error in unsubscribing T0 interrupts.");
    return 1;
  }

  return OK;
}
