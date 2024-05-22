#ifndef _LCOM_I8042_H
#define _LCOM_I8042_H
#include <lcom/lcf.h>

#define DELAY_US 20000

#define KBC_IRQ 1
#define MOUSE_IRQ 12

#define ERROR 1

#define KBC_POLICY (IRQ_REENABLE | IRQ_SETPOLICY | IRQ_EXCLUSIVE)
#define MOUSE_POLICY (IRQ_REENABLE | IRQ_EXCLUSIVE)

#define RB_COMMAND (BIT(7) | BIT(6))
#define TWO_BYTE_LONG_SC (0xE0)

/* I/O port addresses */
#define STAT_REG 0x64  /**< @brief STAT register */
#define IN_BUF  0x64   /**< @brief IN_BUFFER register */
#define IN_BUF_ARGS 0x60  /**< @brief IN_BUFFER_ARGS register */
#define OUT_BUF 0x60     /**< @brief OUT_BUFFER register */


/*Status Register*/
#define STAT_ERROR_HANDLE(status) ((status) & (BIT(7) | BIT(6))) /**< @brief Checks Parity Error and Timeout Error */
#define INPUT_BUFFER (BIT(1))
#define OUTPUT_BUFFER (BIT(0))
#define MOUSE_DATA (BIT(5))
#define OUTPUT_BUFFER_FULL(status) !((status) & (BIT(0))) /**< @brief Checks Output Buffer Full*/

#define BREAK_CODE(makeCode) ((0x80) | makeCode)
#define KBC_ACTIVATE(command_byte) ( command_byte | bit(0))

#define WRITE_BYTE_TO_MOUSE 0xD4
#define MOUSE_ACK 0xFA
#define MOUSE_ERROR 0xFE
#define MOUSE_Y_OVFL BIT(7)
#define MOUSE_X_OVFL BIT(6)
#define MOUSE_MSB_Y_DELTA BIT(5)
#define MOUSE_MSB_X_DELTA BIT(4)
#define MOUSE_MIDDLE_BUTTON BIT(2) 
#define MOUSE_RIGHT_BUTTON BIT(1) 
#define MOUSE_LEFT_BUTTON BIT(0) 
#define DISABLE_DATA_REPORT 0xF5
#define ENABLE_DATA_REPORT  0xF4
#define SET_STREAM_MODE 0xEA

/*KEYS Make Code*/
#define ESC_KEY 0X01
#define A_KEY 0x1e
#define S_KEY 0x1f
#define W_KEY 0x11
#define D_KEY 0x20
#define ENTER_KEY 0X1c
#define SPACE_KEY 0x39
int (kbc_subscribe_int)(uint8_t *bit_no);

int (kbc_unsubscribe_int)();


bool (ready_to_poll)();

#endif  /*_LCOM_I8042_H*/
