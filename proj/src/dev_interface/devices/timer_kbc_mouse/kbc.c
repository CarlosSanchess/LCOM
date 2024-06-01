#include <lcom/lcf.h>
#include "i8042.h"
#include "kbc.h"


bool error = 0;
int kbc_hook_id = 1;


int (kbc_subscribe_int)(uint8_t *bit_no) { 
    if(!bit_no){
      fprintf(stderr,"Invalid Arguments");
      return ERROR;
    }

    *bit_no = BIT(kbc_hook_id); 
    
    if(sys_irqsetpolicy(1, KBC_POLICY, &kbc_hook_id) != OK) return ERROR;  
    
    return OK;
}
int (kbc_unsubscribe_int)(){
      if(sys_irqrmpolicy(&kbc_hook_id) != OK){
          fprintf(stderr,"Error System Call."); 
          return ERROR;
      }
    return OK;
}
int (read_stat_reg)(uint8_t *status){
    if(util_sys_inb(STAT_REG, status) != OK) {return ERROR;}
    return 0;
}
int (read_output_buffer)(uint8_t status, uint8_t *buffer){
    int attemps = 10;
    while(attemps > 0){
        if((status & BIT(0)) != 0){
            if(util_sys_inb(OUT_BUF, buffer) != OK) {return ERROR;}
                if(STAT_ERROR_HANDLE(status) != OK){
                    *buffer = 0;
                    fprintf(stderr, "Problem in Parity or TimeOut");
                    return ERROR;
                }                
            return 0;  
            }    
        attemps--;
        tickdelay(micros_to_ticks(20000));
    }
    return 1;
}

void (kbc_ih)() {
    uint8_t status;
    if(read_stat_reg(&status) != OK){error = 1;}
    if(read_output_buffer(status, &scanCode) != OK){error = 1;}
}

int (write_kbc_command)(uint8_t port, uint8_t commandByte) {

    uint8_t status;
    uint8_t attemps = 10;

    while (attemps) {

        if (read_stat_reg(&status) != 0){
            return 1;
        }

        if ((status & BIT(0) ) == 0){

            if(sys_outb(port, commandByte) != 0){
                return 1;
            }

            return 0;
        }
        tickdelay(micros_to_ticks(20000));
        attemps--;
    }
    
    return 1;
}
