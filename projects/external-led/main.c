#include <avr/io.h>
#include <util/delay.h>

const int ledPin = PB3;

int main(void) {
  DDRB |= 1 << ledPin;

  while (1) {
    PORTB ^= 1 << ledPin;
    _delay_ms(100);
  }
}