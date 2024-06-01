/**
 * @file i8042.h
 * @brief Constants and function declarations for interfacing with the i8042 keyboard controller.
 */

#ifndef _LCOM_I8042_H
#define _LCOM_I8042_H
#include <lcom/lcf.h>

#define DELAY_US 20000 ///< Delay in microseconds for I/O operations

#define KBC_IRQ 1      ///< IRQ line for the keyboard
#define MOUSE_IRQ 12   ///< IRQ line for the mouse

#define ERROR 1        ///< Error code

#define KBC_POLICY (IRQ_REENABLE | IRQ_SETPOLICY | IRQ_EXCLUSIVE) ///< IRQ policy for the keyboard
#define MOUSE_POLICY (IRQ_REENABLE | IRQ_EXCLUSIVE)               ///< IRQ policy for the mouse

#define RB_COMMAND (BIT(7) | BIT(6)) ///< Command for right button press
#define TWO_BYTE_LONG_SC (0xE0)      ///< Two-byte long scan code prefix

/* I/O port addresses */
#define STAT_REG 0x64        ///< Status register
#define IN_BUF  0x64         ///< Input buffer register
#define IN_BUF_ARGS 0x60     ///< Input buffer arguments register
#define OUT_BUF 0x60         ///< Output buffer register

/* Status Register */
#define STAT_ERROR_HANDLE(status) ((status) & (BIT(7) | BIT(6))) ///< Checks Parity Error and Timeout Error in the status register
#define INPUT_BUFFER (BIT(1))       ///< Input buffer status bit
#define OUTPUT_BUFFER (BIT(0))      ///< Output buffer status bit
#define MOUSE_DATA (BIT(5))         ///< Mouse data bit
#define OUTPUT_BUFFER_FULL(status) !((status) & (BIT(0))) ///< Checks if output buffer is full

#define BREAK_CODE(makeCode) ((0x80) | makeCode) ///< Converts make code to break code
#define KBC_ACTIVATE(command_byte) (command_byte | BIT(0)) ///< Activates KBC by setting bit 0 of the command byte

#define WRITE_BYTE_TO_MOUSE 0xD4 ///< Command to write byte to mouse
#define MOUSE_ACK 0xFA           ///< Mouse acknowledgment byte
#define MOUSE_ERROR 0xFE         ///< Mouse error byte
#define MOUSE_Y_OVFL BIT(7)      ///< Mouse Y overflow bit
#define MOUSE_X_OVFL BIT(6)      ///< Mouse X overflow bit
#define MOUSE_MSB_Y_DELTA BIT(5) ///< Mouse most significant bit of Y delta
#define MOUSE_MSB_X_DELTA BIT(4) ///< Mouse most significant bit of X delta
#define MOUSE_MIDDLE_BUTTON BIT(2) ///< Mouse middle button bit
#define MOUSE_RIGHT_BUTTON BIT(1)  ///< Mouse right button bit
#define MOUSE_LEFT_BUTTON BIT(0)   ///< Mouse left button bit
#define DISABLE_DATA_REPORT 0xF5   ///< Command to disable mouse data reporting
#define ENABLE_DATA_REPORT  0xF4   ///< Command to enable mouse data reporting
#define SET_STREAM_MODE 0xEA       ///< Command to set mouse to stream mode

/* Keyboard Make Codes */
#define ESC_KEY 0X01    ///< Make code for ESC key
#define A_KEY 0x1e      ///< Make code for A key
#define S_KEY 0x1f      ///< Make code for S key
#define W_KEY 0x11      ///< Make code for W key
#define D_KEY 0x20      ///< Make code for D key
#define ENTER_KEY 0X1c  ///< Make code for Enter key
#define SPACE_KEY 0x39  ///< Make code for Space key

/**
 * @brief Subscribes keyboard interrupts.
 * 
 * @param bit_no Pointer to the bit number to be set in the mask returned upon an interrupt.
 * @return int Returns 0 upon success, non-zero otherwise.
 */
int (kbc_subscribe_int)(uint8_t *bit_no);

/**
 * @brief Unsubscribes keyboard interrupts.
 * 
 * @return int Returns 0 upon success, non-zero otherwise.
 */
int (kbc_unsubscribe_int)();

/**
 * @brief Checks if the KBC is ready for polling.
 * 
 * @return bool Returns true if ready, false otherwise.
 */
bool (ready_to_poll)();

#endif  /*_LCOM_I8042_H*/
