#include <avr/io.h>

#include "spi.c"

#ifndef _MAX7219_
#define _MAX7219_

#define MAX7219_DECODE_MODE_REG 0x09
#define MAX7219_INTENSITY_REG 0x0a
#define MAX7219_SCAN_LIMIT_REG 0x0b
#define MAX7219_SHUTDOWN_REG 0x0c
#define MAX7219_DISPLAY_TEST_REG 0x0f

void send_to_max7219(uint8_t addr, uint8_t data) {
  spi_transmit(addr);
  spi_transmit(data);

  spi_chip_select();
}

void setup_max7219_led_matrix(void) {
  send_to_max7219(MAX7219_DECODE_MODE_REG, 0);
  send_to_max7219(MAX7219_SCAN_LIMIT_REG, 0xf);
  send_to_max7219(MAX7219_INTENSITY_REG, 0);
  send_to_max7219(MAX7219_DISPLAY_TEST_REG, 0);
  send_to_max7219(MAX7219_SHUTDOWN_REG, 1);
}

#endif