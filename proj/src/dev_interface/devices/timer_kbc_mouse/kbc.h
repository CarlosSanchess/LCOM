#ifndef KBC__H
#define KBC__H

#include <lcom/lcf.h>
#include "i8042.h"

uint8_t scanCode;


int (kbc_subscribe_int)(uint8_t *bit_no);
int (kbc_unsubscribe_int)();
int (read_stat_reg)(uint8_t *status);
int (read_output_buffer)(uint8_t status, uint8_t *buffer);
void (kbc_ih)();
bool (ready_to_poll)();
int (write_kbc_command)(uint8_t port, uint8_t commandByte);

#endif
