#include <avr/io.h>

#ifndef MAX7219_H
#define MAX7219_H

#define MAX7219_DECODE_MODE_REG 0x09
#define MAX7219_INTENSITY_REG 0x0a
#define MAX7219_SCAN_LIMIT_REG 0x0b
#define MAX7219_SHUTDOWN_REG 0x0c
#define MAX7219_DISPLAY_TEST_REG 0x0f

void max7219_send(uint8_t addr, uint8_t data);
void max7219_init();

#endif