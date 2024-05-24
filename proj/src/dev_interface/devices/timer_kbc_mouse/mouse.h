#ifndef MOUSEH 
#define MOUSEH
#include <lcom/lcf.h>
#include "i8042.h"


struct packet mouse_byte_packet;
int mouse_errorHandling;


int (write_mouse)(uint8_t command_byte);
void (mouse_ih)();
void (mouse_packet)();
int (mouse_subscribe_int)(uint8_t *bit_no);
int (mouse_unsubscribe_int)();


#endif
