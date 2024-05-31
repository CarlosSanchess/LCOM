#ifndef RTC_H_
#define RTC_H_

#include <lcom/lcf.h>

#define ERROR 1
#define RTC_IRQ 8
#define RTC_ADDR_REG 0x70
#define RTC_DATA_REG 0x71
#define RTC_UPDATE 0x0A
#define RTC_BINARY 0x0B
#define RTC_SECONDS 0x00
#define RTC_MINUTES 0x02
#define RTC_HOURS 0x04

int (rtc_subscribe_int)(uint8_t *bit_no);
int (rtc_unsubscribe_int)();
int (rtc_read_reg)(uint32_t reg, uint32_t *data);
int (rtc_write_reg)(uint32_t reg, uint32_t data);
bool (rtc_update_in_progress)();
bool (is_rtc_binary)();
int (bcd_to_binary)(uint32_t *bcd);
void (update_rtc_time)(uint8_t *seconds, uint8_t *minutes, uint8_t *hours);

#endif /* RTC_H_ */
