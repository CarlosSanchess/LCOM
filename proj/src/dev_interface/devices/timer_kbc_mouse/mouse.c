#include <lcom/lcf.h>
#include "mouse.h"
#include "kbc.h"

uint8_t mouse_bytes[3];
int mouse_index = 0;
struct packet mouse_byte_packet;
int mouse_errorHandling = 0;
int mouse_hook_id = 2;


int (write_mouse)(uint8_t command_byte){
  int attempts = 10;
  uint8_t byte;

  while(attempts != 0 && byte != MOUSE_ACK){
    write_kbc_command(STAT_REG,WRITE_BYTE_TO_MOUSE);
    write_kbc_command(OUT_BUF,command_byte);
    tickdelay(micros_to_ticks(20000));
    if(util_sys_inb(OUT_BUF,&byte) != OK){return ERROR;}
    if(byte == MOUSE_ACK){
      return 0;
    }
    if((byte == MOUSE_ERROR) || (byte == 0xFC)){
      tickdelay(micros_to_ticks(20000));
    }
    attempts--;
  }
  return ERROR;
}

void (mouse_ih)(){
  uint8_t status;
  if(read_stat_reg(&status) != OK){mouse_errorHandling = 1;}
  if(read_output_buffer(status, mouse_bytes + mouse_index) != OK){mouse_errorHandling = 1;}
  if((mouse_index == 0) && (mouse_bytes[0] & BIT(3))){
    mouse_index++;
  }
  else if(mouse_index < 3){
    mouse_index++;
  }
}

int16_t extend_binary(uint8_t byte) {
    return (0xFF00 | byte);
}

void (mouse_packet)(){
  
  for(int i = 0; i < 3; i++){
    mouse_byte_packet.bytes[i] = mouse_bytes[i];
  }
  mouse_byte_packet.rb = mouse_bytes[0] & MOUSE_RIGHT_BUTTON;
  mouse_byte_packet.lb = mouse_bytes[0] & MOUSE_LEFT_BUTTON;
  mouse_byte_packet.mb = mouse_bytes[0] & MOUSE_MIDDLE_BUTTON;

  if(mouse_bytes[0] & MOUSE_MSB_X_DELTA){
      mouse_byte_packet.delta_x = extend_binary(mouse_bytes[1]);
  }else{
      mouse_byte_packet.delta_x = mouse_bytes[1];
  }
  
  if(mouse_bytes[0] & MOUSE_MSB_Y_DELTA){
      mouse_byte_packet.delta_y = extend_binary(mouse_bytes[2]);
  }else{
      mouse_byte_packet.delta_y = mouse_bytes[2];
  }

  if(!(mouse_bytes[0] & MOUSE_X_OVFL)){
    mouse_byte_packet.x_ov = false;
  }else{
    mouse_byte_packet.x_ov = true;
  }
  if(!(mouse_bytes[0] & MOUSE_Y_OVFL)){
    mouse_byte_packet.y_ov = false;
  }else{
    mouse_byte_packet.y_ov = true;
  }
}

int (mouse_subscribe_int)(uint8_t *bit_no) { 
    if(!bit_no){
      fprintf(stderr,"Invalid Arguments");
      return ERROR;
    }

    *bit_no = BIT(mouse_hook_id); 
    
    if(sys_irqsetpolicy(MOUSE_IRQ, MOUSE_POLICY, &mouse_hook_id) != OK) return ERROR;  
    
    return OK;
}
int (mouse_unsubscribe_int)(){
      if(sys_irqrmpolicy(&mouse_hook_id) != OK){
          fprintf(stderr,"Error System Call."); 
          return ERROR;
      }
    return OK;
}
