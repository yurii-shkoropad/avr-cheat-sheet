#include <avr/io.h>
#include <util/delay.h>

#ifndef _SPI_
#define _SPI_

#define SCK_PIN PB5
#define LATCH_PIN PB2
#define DIN_PIN PB3

void setup_spi(void) {
  DDRB |= _BV(DIN_PIN) | _BV(SCK_PIN) | _BV(LATCH_PIN);

  SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void spi_chip_select(void) {
  PORTB |= _BV(LATCH_PIN);
  _delay_us(1);
  PORTB &= ~_BV(LATCH_PIN);
  _delay_us(1);
}

void spi_transmit(uint8_t data) {
  SPDR = data;
  while(bit_is_clear(SPSR, SPIF));
}

#endif