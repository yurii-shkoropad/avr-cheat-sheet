#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <avr/interrupt.h>

const int ledPin = PB3;

ISR(TIMER1_COMPA_vect) {
  PORTB ^= 1 << ledPin;
}

void setupTimer(void);

int main(void) {
  DDRB |= 1 << ledPin;

  setupTimer();

  while (1);
}

void setupTimer(void) {
  TIMSK1 |= 1 << OCIE1A;
  TCCR1B = (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10); // 1024

  OCR1A = 15625; // 16Mhz / 1024 / 15625 = 1 times in second 

  sei();
} 