#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <avr/interrupt.h>

const int testPin = PB5;

ISR(TIMER1_COMPA_vect) {
  PORTB ^= 1 << testPin;
}

void setupTimer(void);

int main(void) {
  DDRB |= 1 << testPin;

  setupTimer();

  while (1);
}

void setupTimer(void) {
  TIMSK1 |= 1 << OCIE1A; // Enable the compare match interrupt (OCIE0A Bit for Compare Match A interrupt)
  TCCR1B = (1 << WGM12); // Set Timer/Counter 0 to CTC mode
  TCCR1B |= (1 << CS12) | (1 << CS10); // Set prescaler to 1024;

  OCR1A = 15625; // Set OCR0A compare match value (max 255 as it is 8 bit register). 16Mhz / 1024 / 15625 = 1 times in second 

  sei();
} 