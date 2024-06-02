#include "serial_port.h"

static int hook_id = 15;


static int fifo_is_empty(fifo_t *fifo) {
    return fifo->count == 0;
}

static int fifo_is_full(fifo_t *fifo) {
    return fifo->count == FIFO_SIZE;
}

int fifo_enqueue(fifo_t *fifo, uint8_t data) {
    if (fifo_is_full(fifo)) {
        return 1; 
    }
    fifo->buffer[fifo->tail] = data;
    fifo->tail = (fifo->tail + 1) % FIFO_SIZE;
    fifo->count++;
    return 0;
}

 uint8_t fifo_dequeue(fifo_t *fifo) {
    if (fifo_is_empty(fifo)) {
        return 1;  
    }
    uint8_t data = fifo->buffer[fifo->head];
    fifo->head = (fifo->head + 1) % FIFO_SIZE;
    fifo->count--;
    return data;
}

int serial_subscribe_int(uint8_t *bit_no) {
    *bit_no = BIT(hook_id);
    if (sys_irqsetpolicy(4, IRQ_REENABLE | IRQ_EXCLUSIVE, &hook_id) != OK) {
        return 1;
    }
    return 0;
}

int serial_unsubscribe_int() {
    if (sys_irqrmpolicy(&hook_id) != OK) {
        return 1;
    }
    return 0;
}

int stat_error(uint8_t stat) {
    return (stat & STAT_ERROR) != 0;
}

int serial_int_handler(fifo_t *rx_fifo) {
    uint8_t iir;
    uint8_t stat;
    uint8_t data;
    if(util_sys_inb(SERIAL_PORT_COM1 + UART_IIR, &iir) != OK) return 1;  
    
    if (iir & UART_IIR_RDI) { 
        if(serial_stat(&stat) != 0) {
            return 1;
        }
        if(!(stat & STAT_READY)) {
            return 1;
        }
        if(stat_error(stat)) {
            return 1;
        }
        util_sys_inb(SERIAL_PORT_COM1 + UART_RBR, &data);  
        fifo_enqueue(rx_fifo, data);
    }
    return 0;
}

int send_byte(uint8_t byte) {
    uint8_t stat;
    if(serial_stat(&stat) != 0) {
        return 1;
    }
    if(!(stat & STAT_READY)) {
        return 1;
    }
    if(stat_error(stat)) {
        return 1;
    }
    if(sys_outb(SERIAL_PORT_COM1 + UART_THR, byte) != OK) {
        return 1;
    }
    printf("sent");
    return 0;
}

int serial_config() {
    uint8_t ier;
    if(util_sys_inb(SERIAL_PORT_COM1 + UART_IER, &ier) != OK) {
        return 1;
    }
    ier &= ~UART_IER_RDI;  
    ier &= ~UART_IER_THRI;
    if(sys_outb(SERIAL_PORT_COM1 + UART_IER, ier) != OK) {
        return 1;
    }
    return 0;
}

int serial_stat(uint8_t *stat) {
    if(util_sys_inb(SERIAL_PORT_COM1 + UART_LSR, stat) != OK) {
        return 1;
    }
    return 0;
}

int serial_clear_fifo(fifo_t *rx_fifo, fifo_t *tx_fifo) {
    if(sys_outb(SERIAL_PORT_COM1 + UART_FCR, UART_FCR_CLEAR) != OK) {
        return 1;
    }
    rx_fifo->head = 0;
    rx_fifo->tail = 0;
    rx_fifo->count = 0;
    tx_fifo->head = 0;
    tx_fifo->tail = 0;
    tx_fifo->count = 0;
    return 0;
}

