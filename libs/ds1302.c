#include "ds1302.h"
#include <stdbool.h>
#include <util/delay.h>

void ds1302_init(void) {
  DDRD |= _BV(DS1302_SCK_PIN) | _BV(DS1302_DAT_PIN) | _BV(DS1302_RST_PIN);
  PORTD &= ~(_BV(DS1302_SCK_PIN) | _BV(DS1302_DAT_PIN) | _BV(DS1302_RST_PIN));
}

void d1302_start_transmission(void) {
  PORTD |= _BV(DS1302_RST_PIN);
}

void d1302_end_transmission(void) {
  PORTD &= ~(_BV(DS1302_RST_PIN));
}

void ds1302_send_byte(uint8_t byte, bool read_after) {
  DDRD |= _BV(DS1302_DAT_PIN);
  PORTD &= ~(_BV(DS1302_DAT_PIN));

  for(uint8_t i = 0; i < 8; i++) {
    if(bit_is_set(byte, i)) {
      PORTD |= _BV(DS1302_DAT_PIN);
    } else {
      PORTD &= ~(_BV(DS1302_DAT_PIN));
    }
    _delay_us(DS1302_DELAY_USEC);
    PORTD |= _BV(DS1302_SCK_PIN);

    if (read_after && i == 7) {
      DDRD &= ~(1 << DS1302_DAT_PIN);
    } else {
      _delay_us(DS1302_DELAY_USEC);
      PORTD &= ~(_BV(DS1302_SCK_PIN));
    }
  }
}

uint8_t ds1302_read_byte() {
  uint8_t data = 0;

  for(uint8_t i = 0; i < 8; i++) {
    PORTD |= (1 << DS1302_SCK_PIN);
    _delay_us(DS1302_DELAY_USEC);
    PORTD &= ~(1 << DS1302_SCK_PIN);
    _delay_us(DS1302_DELAY_USEC);

    if(PIND & (1 << DS1302_DAT_PIN)) {
      data |= (1 << i);
    }
  }

  return data;
}

void ds1302_write(uint8_t command, uint8_t data) {
  d1302_start_transmission();

  ds1302_send_byte(command, false);
  ds1302_send_byte(data, false);

  d1302_end_transmission();
}

uint8_t ds1302_read(uint8_t command) {
  d1302_start_transmission();
  ds1302_send_byte(command, true);

  uint8_t data = ds1302_read_byte();

  d1302_end_transmission();

  return data;
}

void ds1302_read_burst(uint8_t command, uint8_t size, uint8_t *target) {
  d1302_start_transmission();
  ds1302_send_byte(command, true);

  for(uint8_t i = 0; i < size; i++) {
    uint8_t tmp = ds1302_read_byte();
    target[i] = tmp;
  }
  d1302_end_transmission();
}

void ds1302_write_burst(uint8_t command, uint8_t size, uint8_t *target) {
  d1302_start_transmission();
  ds1302_send_byte(command, false);

  for(uint8_t i = 0; i < size; i++) {
    ds1302_send_byte(target[i], false);
  }
  d1302_end_transmission();
}

void ds1302_ram_burst_read(uint8_t *target) {
  ds1302_read_burst(DS1302_RAM_BURST_READ, 31, target);
}

void ds1302_ram_burst_write(uint8_t *target) {
  ds1302_write_burst(DS1302_RAM_BURST_WRITE, 31, target);
}

void ds1302_clock_burst_read(uint8_t *target) {
  ds1302_read_burst(DS1302_CLOCK_BURST_READ, 9, target);
}

void ds1302_clock_burst_write(uint8_t *target) {
  ds1302_write_burst(DS1302_CLOCK_BURST_WRITE, 9, target);
}

uint8_t ds1302_read_week_day(void) {
  return ds1302_read(DS1302_CLOCK_WEEK_DAY_READ);
}

uint8_t year_byte_to_year(uint8_t year_byte) {
  uint8_t year_decade = (year_byte >> 4) * 10;
  uint8_t year = (year_byte & 0xf);
  return year_decade + year;
}

uint8_t month_byte_to_month(uint8_t month_byte) {
  uint8_t month_decade = (month_byte >> 4) * 10;
  uint8_t month = (month_byte & 0xf);
  return month_decade + month;
}

uint8_t date_byte_to_date(uint8_t date_byte) {
  uint8_t date_decade = (date_byte >> 4) * 10;
  uint8_t date = (date_byte & 0xf);
  return date_decade + date;
}

uint8_t hour_byte_to_hour(uint8_t hour_byte) {
  uint8_t adj;
  if (hour_byte & 128) {
    adj = 12 * ((hour_byte & 32) >> 5);
  } else {
    adj = 10 * ((hour_byte & (32 + 16)) >> 4);
  }
  return (hour_byte & 15) + adj;
}

uint8_t minutes_byte_to_minutes(uint8_t minutes_byte) {
  uint8_t minutes_decade = (minutes_byte >> 4) * 10;
  uint8_t minutes = (minutes_byte & 0xf);
  return minutes_decade + minutes;
}

uint8_t seconds_byte_to_seconds(uint8_t seconds_byte) {
  uint8_t seconds_decade = ((seconds_byte & 0x7F) >> 4) * 10;
  uint8_t seconds = (seconds_byte & 0xf);
  return seconds_decade + seconds;
}

uint8_t ds1302_read_year(void) {
  uint8_t year_byte = ds1302_read(DS1302_CLOCK_YEAR_READ);
  return year_byte_to_year(year_byte);
}

uint8_t ds1302_read_month(void) {
  uint8_t month_byte = ds1302_read(DS1302_CLOCK_MONTH_READ);
  return month_byte_to_month(month_byte);
}

uint8_t ds1302_read_date(void) {
  uint8_t date_byte = ds1302_read(DS1302_CLOCK_DATE_READ);
  return date_byte_to_date(date_byte);
}

uint8_t ds1302_read_hour(void) {
  uint8_t hour_byte = ds1302_read(DS1302_CLOCK_HOUR_READ);
  return hour_byte_to_hour(hour_byte);
}

uint8_t ds1302_read_minutes(void) {
  uint8_t minutes_byte = ds1302_read(DS1302_CLOCK_MINUTES_READ);
  return minutes_byte_to_minutes(minutes_byte);
}

uint8_t ds1302_read_seconds(void) {
  uint8_t seconds_byte = ds1302_read(DS1302_CLOCK_SECONDS_READ);
  return seconds_byte_to_seconds(seconds_byte);
}

void ds1302_read_time(uint8_t *target) {
  uint8_t clock_bytes[9];
  ds1302_clock_burst_read(clock_bytes);

  target[0] = seconds_byte_to_seconds(clock_bytes[0]);
  target[1] = minutes_byte_to_minutes(clock_bytes[1]);
  target[2] = hour_byte_to_hour(clock_bytes[2]);
  target[3] = date_byte_to_date(clock_bytes[3]);
  target[4] = month_byte_to_month(clock_bytes[4]);
  // skipping weekday
  target[5] = year_byte_to_year(clock_bytes[6]);
}

bool ds1302_read_protect(void) {
  uint8_t protect_byte = ds1302_read(DS1302_PROTECT_READ);
  return protect_byte >> 7;
}

void ds1302_write_protect(bool is_protected) {
  ds1302_write(DS1302_PROTECT_WRITE, is_protected << 7);
}