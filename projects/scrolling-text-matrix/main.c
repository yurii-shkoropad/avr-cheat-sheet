#include <avr/io.h>
#include <util/delay.h>

#include "./src/matrix7219.c"

const uint8_t devices = 4;

void main(void) {
  setup_max7219_led_matrix(devices);
  clean_max7219(devices);

  while (1) {
    draw_scrolling_text_4_max7219("hello world");
  }
}