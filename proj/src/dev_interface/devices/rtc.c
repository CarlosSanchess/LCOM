#include <lcom/lcf.h>

#include "rtc.h"

int rtc_hook_id = 5;

int (rtc_subscribe_int)(uint8_t *bit_no) {
    *bit_no = rtc_hook_id;
    if (sys_irqsetpolicy(RTC_IRQ, IRQ_REENABLE, &rtc_hook_id) != OK) {
        fprintf(stderr, "Error in rtc_subscribe_int\n");
        return ERROR;
    }
    return OK;
}

int (rtc_unsubscribe_int)() {
    if (sys_irqrmpolicy(&rtc_hook_id) != OK) {
        fprintf(stderr, "Error in rtc_unsubscribe_int\n");
        return ERROR;
    }
    return OK;
}

int (rtc_read_reg)(uint8_t reg, uint8_t *data) {
    if (sys_outb(RTC_ADDR_REG, reg) != OK) {
        fprintf(stderr, "Error in rtc_read_reg\n");
        return ERROR;
    }
    if (util_sys_inb(RTC_DATA_REG, data) != OK) {
        fprintf(stderr, "Error in rtc_read_reg\n");
        return ERROR;
    }
    return OK;
}

bool (rtc_update_in_progress)() {
    uint8_t ret;
    if (rtc_read_reg(RTC_UPDATE, &ret) != OK) {
        fprintf(stderr, "Error in rtc_update_in_progress\n");
        return ERROR;
    }
    return ret & BIT(7);
}

bool (is_rtc_binary)() {
    uint8_t ret;
    if (rtc_read_reg(RTC_BINARY, &ret) != OK) {
        fprintf(stderr, "Error in is_rtc_binary\n");
        return ERROR;
    }
    return ret & BIT(2);
}

int bcd_to_binary(uint8_t *bcd) {
    *bcd = ((*bcd >> 4) * 10) + (*bcd & 0xF);
    return OK;
}

void (update_rtc_time)(uint8_t *seconds, uint8_t *minutes, uint8_t *hours) {
    uint8_t seconds_reg, minutes_reg, hours_reg;
    if (rtc_update_in_progress() != OK) {
        return;
    }
    rtc_read_reg(RTC_SECONDS, &seconds_reg);
    rtc_read_reg(RTC_MINUTES, &minutes_reg);
    rtc_read_reg(RTC_HOURS, &hours_reg);
    if (!is_rtc_binary()) {
        bcd_to_binary(&seconds_reg);
        bcd_to_binary(&minutes_reg);
        bcd_to_binary(&hours_reg);   
    }
    *seconds = seconds_reg;
    *minutes = minutes_reg;
    *hours = hours_reg; 
}
