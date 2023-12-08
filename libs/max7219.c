#include <avr/io.h>
#include "led-matrix-text.c"
#include "spi.c"

#ifndef _MAX7219_
#define _MAX7219_

#define MAX7219_DECODE_MODE_REG 0x09
#define MAX7219_INTENSITY_REG 0x0a
#define MAX7219_SCAN_LIMIT_REG 0x0b
#define MAX7219_SHUTDOWN_REG 0x0c
#define MAX7219_DISPLAY_TEST_REG 0x0f

void send_to_max7219(uint8_t addr, uint8_t data, uint8_t selected_device, uint8_t total_devices) {
  for (uint8_t i = 0; i < total_devices; i++) {
    if (selected_device == i) {
      spi_transmit(addr);
      spi_transmit(data);
    } else {
      spi_transmit(0);
      spi_transmit(0);
    }
  }

  spi_chip_select();
}

void draw_max7219(uint8_t data[8][8], uint8_t selected_device, uint8_t total_devices) {
  for (uint8_t r = 0; r < 8; r++) {
    uint8_t row = 0;
    for (uint8_t i = 0; i < 8; i++) {
        if (data[r][i]) {
          row |= _BV(7 - i);
        }
    }
    send_to_max7219(r + 1, row, selected_device, total_devices);
  }
}

void draw_binary_max7219(uint8_t data[8], uint8_t selected_device, uint8_t total_devices) {
  for (uint8_t r = 0; r < 8; r++) {
    send_to_max7219(r + 1, data[r], selected_device, total_devices);
  }
}

void draw_letter_max7219(char letter, uint8_t selected_device, uint8_t total_devices) {
  uint8_t letterArray[8];

  copy_letter_to_array(letterArray, letter);

  draw_binary_max7219(letterArray, selected_device, total_devices);
}

void draw_scrolling_text_4_max7219(char* str) {
  for (int i = 0; i != '\0'; i++) {
    char letter = str[i];
  }
}

void clean_max7219(uint8_t total_devices) {
  for (uint8_t i = 0; i < total_devices; i++) {
    for (uint8_t r = 0; r < 8; r++) {
      send_to_max7219(r + 1, 0, i, total_devices);
    }
  }
}

void setup_max7219_led_matrix(uint8_t devices) {
  setup_spi();

  for (uint8_t i = 0; i < devices; i++) {
    send_to_max7219(MAX7219_DECODE_MODE_REG, 0, i, devices);
    send_to_max7219(MAX7219_SCAN_LIMIT_REG, 0xf, i, devices);
    send_to_max7219(MAX7219_INTENSITY_REG, 0, i, devices);
    send_to_max7219(MAX7219_DISPLAY_TEST_REG, 0, i, devices);
    send_to_max7219(MAX7219_SHUTDOWN_REG, 1, i, devices);
  }
}

#endif