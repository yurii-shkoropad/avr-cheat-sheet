#include <avr/io.h>
#include <stdbool.h>

#ifndef _DS1302_H_ 
#define _DS1302_H_ 

#define DS1302_SCK_PIN PD6
#define DS1302_DAT_PIN PD7
#define DS1302_RST_PIN PD4

#define DS1302_DELAY_USEC 3

#define DS1302_RAM_BURST_READ 0xFF
#define DS1302_RAM_BURST_WRITE 0xFE

#define DS1302_CLOCK_BURST_READ 0xBF
#define DS1302_CLOCK_BURST_WRITE 0xBE

#define DS1302_CLOCK_SECONDS_READ 0x81
#define DS1302_CLOCK_SECONDS_WRITE 0x80
#define DS1302_CLOCK_MINUTES_READ 0x83
#define DS1302_CLOCK_HOUR_READ 0x85
#define DS1302_CLOCK_DATE_READ 0x87
#define DS1302_CLOCK_MONTH_READ 0x89
#define DS1302_CLOCK_WEEK_DAY_READ 0x8B
#define DS1302_CLOCK_YEAR_READ 0x8D

#define DS1302_PROTECT_READ 0x8F
#define DS1302_PROTECT_WRITE 0x8E

void ds1302_init(void);
void ds1302_write(uint8_t command, uint8_t data);
uint8_t ds1302_read(uint8_t command);

void ds1302_ram_burst_read(uint8_t *target);
void ds1302_ram_burst_write(uint8_t *target);

void ds1302_clock_burst_read(uint8_t *target);
void ds1302_clock_burst_write(uint8_t *target);

uint8_t ds1302_read_seconds(void);
uint8_t ds1302_read_month(void);
uint8_t ds1302_read_week_day(void);
uint8_t ds1302_read_year(void);
uint8_t ds1302_read_date(void);
uint8_t ds1302_read_hour(void);
uint8_t ds1302_read_minutes(void);

void ds1302_read_time(uint8_t *target);

bool ds1302_read_protect(void);
void ds1302_write_protect(bool is_protected);

#endif 