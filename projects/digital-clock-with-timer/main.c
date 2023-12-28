#include <avr/io.h>
#include "src/spi.h"
#include "src/max7219.h"

int main(void) {
  DDRB |= _BV(PB5);
  // PORTB &= ~_BV(PB5);
  PORTB |= _BV(PB5);

  init_spi();
  max7219_init();
}