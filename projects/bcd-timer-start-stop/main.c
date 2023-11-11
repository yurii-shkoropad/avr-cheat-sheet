#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>

const int btnPin = PD2;
const int ledPin1 = PD4;
const int ledPin2 = PD5;
const int ledPin3 = PD6;
const int ledPin4 = PD7;
const int ledPin5 = PB0;
const int ledPin6 = PB1;
const int ledPin7 = PB2;
const int ledPin8 = PB3;

void setupPins(void);
void setupTimer(void);
void setupBtnInterrupt(void);
void light(uint8_t data);

volatile uint8_t bcdCounter = 0;
volatile bool isRunning = false;

ISR(TIMER1_COMPA_vect) {
  if (!isRunning) {
    return;
  }
  bcdCounter++;
  if (bcdCounter > 255) {
    bcdCounter = 0;
  }
  light(bcdCounter);
}

ISR(INT0_vect) {
 isRunning = !isRunning;
}

int main(void) {
  setupPins();
  setupTimer();
  setupBtnInterrupt();
  sei();

  while (1);
}

void setupPins() {
  DDRD |= _BV(ledPin1) | _BV(ledPin2) | _BV(ledPin3) | _BV(ledPin4);
  DDRB |= _BV(ledPin5) | _BV(ledPin6) | _BV(ledPin7) | _BV(ledPin8);

  DDRD &= ~_BV(btnPin);

  PORTD |= _BV(btnPin); // set pull up resistor
}

void setupTimer(void) {
  TIMSK1 |= 1 << OCIE1A;
  TCCR1B = (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10); // 1024

  OCR1A = 15625; // 16Mhz / 1024 / 15625 = 1 times in second 
}

void light(uint8_t data) {
  if (bit_is_set(data, 0)) {
    PORTD |= _BV(ledPin1);
  } else {
    PORTD &= ~_BV(ledPin1);
  }

  if (bit_is_set(data, 1)) {
    PORTD |= _BV(ledPin2);
  } else {
    PORTD &= ~_BV(ledPin2);
  }

  if (bit_is_set(data, 2)) {
    PORTD |= _BV(ledPin3);
  } else {
    PORTD &= ~_BV(ledPin3);
  }

  if (bit_is_set(data, 3)) {
    PORTD |= _BV(ledPin4);
  } else {
    PORTD &= ~_BV(ledPin4);
  }

  if (bit_is_set(data, 4)) {
    PORTB |= _BV(ledPin5);
  } else {
    PORTB &= ~_BV(ledPin5);
  }

  if (bit_is_set(data, 5)) {
    PORTB |= _BV(ledPin6);
  } else {
    PORTB &= ~_BV(ledPin6);
  }

  if (bit_is_set(data, 6)) {
    PORTB |= _BV(ledPin7);
  } else {
    PORTB &= ~_BV(ledPin7);
  }

  if (bit_is_set(data, 7)) {
    PORTB |= _BV(ledPin8);
  } else {
    PORTB &= ~_BV(ledPin8);
  }
}

void setupBtnInterrupt(void) {
  EIMSK |= 1 << INT0;
  EICRA |= 1 << ISC01;
} 