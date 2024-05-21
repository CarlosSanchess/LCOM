#include <lcom/lcf.h>
#include <lcom/timer.h>

#include <stdint.h>
#include <stdio.h>

#include "i8254.h"




#define INI_VALUES(x)(x & 0x30)
#define COUNT_MODE(x)(x & 0x0E)
#define BASE_VALUES(x)(x & 0x01)
#define TIMER_TO_PORT(x)(x + 0x40)
#define ERROR 1



unsigned int timer_counter = 0;
int hook_id = 0;



int (timer_set_frequency)(uint8_t timer, uint32_t freq) {
  if(freq > TIMER_FREQ ){
    fprintf(stderr, "Invalid Arguments.");
    return 1;
  }
  if(UINT16_MAX < TIMER_FREQ / freq){
    fprintf(stderr,"Invalid wanted freq, data overflow.");
    return 1;
  }

  uint16_t initalTimer = TIMER_FREQ / freq; 
  uint8_t msb;
  uint8_t lsb;

  if(util_get_LSB(initalTimer, &lsb) != OK) return ERROR; 
  if(util_get_MSB(initalTimer, &msb) != OK) return ERROR;

  uint8_t controlWord; 
  timer_get_conf(timer, &controlWord);

  controlWord = (controlWord & 0x0F) | TIMER_LSB_MSB ;
  if(sys_outb(TIMER_CTRL, controlWord) != OK) return ERROR; 
  
  if(sys_outb(TIMER_TO_PORT(timer), lsb) != OK) return ERROR;  
  if(sys_outb(TIMER_TO_PORT(timer), msb) != OK) return ERROR;  

  return OK;
}

int (timer_subscribe_int)(uint8_t *bit_no) { 
    if(!bit_no){
      fprintf(stderr,"Invalid Arguments");
      return ERROR;
    }
    if(hook_id != OK){
      fprintf(stderr,"Timer 0 interrupts, were already enable");
      return ERROR;
    }

    *bit_no = BIT(hook_id); 
    
    if(sys_irqsetpolicy(TIMER0_IRQ, IRQ_REENABLE, &hook_id) != OK) return ERROR;  

    return OK;
}

int (timer_unsubscribe_int)() {
  if(sys_irqrmpolicy(&hook_id) != OK){
      fprintf(stderr,"Error System Call."); 
      return ERROR;
    }
    hook_id = 0;
    return OK;
}

void (timer_int_handler)(){ 
    timer_counter++;
}    


int (timer_get_conf)(uint8_t timer, uint8_t *st) {
  if(!st || timer > 2){
    fprintf(stderr, "Invalid Arguments.");
    return ERROR;
  }
  uint8_t command = TIMER_RB_CMD | TIMER_RB_COUNT_ | TIMER_RB_SEL(timer); 

  if(sys_outb(TIMER_CTRL, command) != OK){
    fprintf(stderr,"Error System Call.");
    return ERROR;
  }

  int port = TIMER_TO_PORT(timer);

  if(util_sys_inb(port, st) != OK ){
    fprintf(stderr,"Error System Call.");
    return ERROR;
  }

  return OK;
}

int (timer_display_conf)(uint8_t timer, uint8_t st, // MAnter os st?
                        enum timer_status_field field) { 
                          
  
  union timer_status_field_val configData;
  switch (field)
  {
  case tsf_all: 
      configData.byte = st;
    break;
  case tsf_initial: 
        st = INI_VALUES(st) >> 4;    
        if(st == 0){fprintf(stderr, "Invalid Initialization Mode."); return 1;}

        if(st == 1){  
          configData.in_mode = LSB_only;
        }
        if(st == 2){
          configData.in_mode = MSB_only;
        }
        if(st == 3){
          configData.in_mode = MSB_after_LSB;
        }
    break;
  case tsf_mode:  // 3 2 1     000000111 
        st =  COUNT_MODE(st) >> 1;
        if(st == 6 || st == 7){
          st &= 0xF7;
        }
        configData.count_mode = st;      
    break;
  case tsf_base:
        st = BASE_VALUES(st); 
        configData.bcd = st;
    break;

  default: 
    fprintf(stderr, "Invalid Arguments.");
    return ERROR;
  }
  timer_print_config(timer, field, configData);
  return OK;
}

