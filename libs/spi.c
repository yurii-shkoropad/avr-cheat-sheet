#include <avr/io.h>
#include <util/delay.h>

#include "spi.h"

void init_spi(void) {
  DDRB |= _BV(DATA_PIN) | _BV(SCK_PIN) | _BV(LATCH_PIN);

  SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI, MSTR - MOSI, fck/16
}

void spi_transmit(uint8_t data) {
  SPDR = data;
  while(bit_is_clear(SPSR, SPIF));
}

void spi_latch(void) {
  PORTB |= _BV(LATCH_PIN);
  _delay_us(1);
  PORTB &= ~_BV(LATCH_PIN);
  _delay_us(1);
}