#include <avr/io.h>
#include <string.h>

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
  0b11111110,
  0b11000011,
  0b11000011,
  0b11000011,
  0b11000011,
  0b11000011,
  0b11000011,
  0b11111110
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
  0b11000110,
  0b11000110,
  0b11000110,
  0b11111110,
  0b11000110,
  0b11000110,
  0b11000110,
  0b11000110
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
  0b00000000
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
  }
}
