#include "serialPortController.h"

static fifo_t rx_fifo = { .head = 0, .tail = 0, .count = 0 };
// static fifo_t tx_fifo = { .head = 0, .tail = 0, .count = 0 };

int handleSPInterrupt(MSTATE *state){
    send_byte(0x00);
    serial_int_handler(&rx_fifo);
    uint8_t data; 
    data = fifo_dequeue(&rx_fifo);
    if(data == 0x00){
        send_byte(0x01);
        serial_int_handler(&rx_fifo);
          data = fifo_dequeue(&rx_fifo);
         if(data == 0x01){
            *state = CONNECTED;
            printf("connected");
        }
    }

    return 0;
}

