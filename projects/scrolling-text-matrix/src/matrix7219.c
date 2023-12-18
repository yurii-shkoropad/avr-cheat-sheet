#include <avr/io.h>
#include <string.h>
#include <stdio.h>
#include <util/delay.h>
#include "spi.c"

#define MAX7219_DECODE_MODE_REG 0x09
#define MAX7219_INTENSITY_REG 0x0a
#define MAX7219_SCAN_LIMIT_REG 0x0b
#define MAX7219_SHUTDOWN_REG 0x0c
#define MAX7219_DISPLAY_TEST_REG 0x0f

uint8_t a_8_by_8[8] = {
  0b00111100,
  0b01100110,
  0b11000011,
  0b11000011,
  0b11111111,
  0b11000011,
  0b11000011,
  0b11000011
};

uint8_t b_8_by_8[8] = {
  0b11111100,
  0b11000110,
  0b11000110,
  0b11111100,
  0b11000110,
  0b11000110,
  0b11000110,
  0b11111100
};

uint8_t c_8_by_8[8] = {
  0b00111110,
  0b01100000,
  0b11000000,
  0b11000000,
  0b11000000,
  0b11000000,
  0b01100000,
  0b00111110
};

uint8_t d_8_by_8[8] = {
  0b11111000,
  0b11001100,
  0b11000110,
  0b11000110,
  0b11000110,
  0b11000110,
  0b11001100,
  0b11111000
};

uint8_t e_8_by_8[8] = {
  0b11111111,
  0b11000000,
  0b11000000,
  0b11111100,
  0b11000000,
  0b11000000,
  0b11000000,
  0b11111111
};

uint8_t f_8_by_8[8] = {
  0b11111111,
  0b11000000,
  0b11000000,
  0b11111100,
  0b11000000,
  0b11000000,
  0b11000000,
  0b11000000
};

uint8_t g_8_by_8[8] = {
  0b00111110,
  0b01100000,
  0b11000000,
  0b11001110,
  0b11000011,
  0b01100011,
  0b00111110,
  0b00000000
};

uint8_t h_8_by_8[8] = {
  0b11000011,
  0b11000011,
  0b11000011,
  0b11111111,
  0b11000011,
  0b11000011,
  0b11000011,
  0b11000011
};

uint8_t i_8_by_8[8] = {
  0b00111100,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00011000,
  0b00111100,
  0b00000000
};

uint8_t j_8_by_8[8] = {
  0b00001110,
  0b00000110,
  0b00000110,
  0b00000110,
  0b11000110,
  0b11000110,
  0b01111100,
  0b00000000
};

uint8_t k_8_by_8[8] = {
  0b11000110,
  0b11001100,
  0b11011000,
  0b11110000,
  0b11110000,
  0b11011000,
  0b11001100,
  0b11000110
};

uint8_t l_8_by_8[8] = {
  0b11000000,
  0b11000000,
  0b11000000,
  0b11000000,
  0b11000000,
  0b11000000,
  0b11111111,
  0b11111111
};

uint8_t m_8_by_8[8] = {
  0b10000001,
  0b11000011,
  0b10100101,
  0b10011001,
  0b10000001,
  0b10000001,
  0b10000001,
  0b10000001
};

uint8_t n_8_by_8[8] = {
  0b10000001,
  0b11000001,
  0b10100001,
  0b10010001,
  0b10001001,
  0b10000101,
  0b10000011,
  0b10000001
};

uint8_t o_8_by_8[8] = {
  0b00111100,
  0b01100110,
  0b11000011,
  0b11000011,
  0b11000011,
  0b11000011,
  0b01100110,
  0b00111100
};

uint8_t r_8_by_8[8] = {
  0b11111100,
  0b11000110,
  0b11000110,
  0b11111100,
  0b11011000,
  0b11001100,
  0b11000110,
  0b11000011
};

uint8_t w_8_by_8[8] = {
  0b10000001,
  0b10000001,
  0b10000001,
  0b10000001,
  0b10011001,
  0b10100101,
  0b11000011,
  0b10000001
};

uint8_t space_8_by_8[8] = {
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
};

void copy_letter_to_array(uint8_t destination[8], char letter) {
  switch (letter) {
    case 'a':
      memcpy(destination, a_8_by_8, 8);
      break;
    case 'b':
      memcpy(destination, b_8_by_8, 8);
      break;
    case 'c':
      memcpy(destination, c_8_by_8, 8);
      break;
    case 'd':
      memcpy(destination, d_8_by_8, 8);
      break;
    case 'e':
      memcpy(destination, e_8_by_8, 8);
      break;
    case 'g':
      memcpy(destination, g_8_by_8, 8);
      break;
    case 'h':
      memcpy(destination, h_8_by_8, 8);
      break;
    case 'i':
      memcpy(destination, i_8_by_8, 8);
      break;
    case 'j':
      memcpy(destination, j_8_by_8, 8);
      break;
    case 'k':
      memcpy(destination, j_8_by_8, 8);
      break;
    case 'l':
      memcpy(destination, l_8_by_8, 8);
      break;
    case 'm':
      memcpy(destination, m_8_by_8, 8);
      break;
    case 'n':
      memcpy(destination, n_8_by_8, 8);
      break;
    case 'o':
      memcpy(destination, o_8_by_8, 8);
      break;
    case 'r':
      memcpy(destination, r_8_by_8, 8);
      break;
    case 'w':
      memcpy(destination, w_8_by_8, 8);
      break;
    case ' ':
      memcpy(destination, space_8_by_8, 8);
      break;
  }
}


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

void draw_4_max7219(uint8_t data[8][32]) {
  for (uint8_t r = 0; r < 8; r++) {
    for (uint8_t dev_i = 0; dev_i < 4; dev_i++) {
      uint8_t row = 0;
      for (uint8_t c = 0; c < 8; c++) {
        if (data[r][c + dev_i * 8]) {
          row |= _BV(7 - c);
        }
      }
      spi_transmit(r + 1);
      spi_transmit(row);
    }
    spi_chip_select();
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
  int size = strlen(str);
  int matrix_size = 8 * 4;
  int arr_size = 2 * matrix_size + size * 8 + (size - 1) * 2;

  uint8_t movie[8][arr_size];

  for (int c = 0; c < arr_size; c++) {
    for (int r = 0; r < 8; r++) {
      if (c < matrix_size || c > arr_size - matrix_size - 1) {
        movie[r][c] = 0;
      } else {
        movie[r][c] = 1;
      }
    }
  }

  for (int i = 0; str[i] != '\0'; i++) {
    char letter = str[i];
    uint8_t letterArr[8];
    copy_letter_to_array(letterArr, letter);

    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < 10; c++) {
        if (c >= 8 || bit_is_clear(letterArr[r], 7 - c)) {
          movie[r][matrix_size + (c + (i) * 10)] = 0;
        }
      }
    }
  }

  for (int p = 0; p < arr_size - matrix_size; p++) {
    uint8_t scene[8][matrix_size];
    for (int r = 0; r < 8; r++) {
      for (int c = 0; c < matrix_size; c++) {
        scene[r][c] = movie[r][c + p];
      }
    }

    draw_4_max7219(scene);
    _delay_ms(100);
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