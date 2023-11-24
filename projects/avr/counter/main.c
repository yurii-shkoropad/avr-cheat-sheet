#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>

const uint8_t dataPin = PB3; // PICO, MOSI
const uint8_t sckPin = PB5; // Serial clock
const uint8_t latchPin = PB2; 
const int btnPin = PD2;
volatile int counter = 0;

enum BtnPressType {
  SHORT_PRESS,
  LONG_PRESS
};

#ifndef F_CPU
#define F_CPU 16000000
#endif

void USARTInit(uint32_t baud) {
  UBRR0H = (uint8_t)((F_CPU / (16 * baud) - 1) >> 8);
  UBRR0L = (uint8_t)(F_CPU / (16 * baud) - 1);
  UCSR0A = 0;

  UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
  UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void USARTPutChar(uint8_t data) {
  while (!(UCSR0A & (1 << UDRE0)));

  UDR0 = data;
}

void printUSARTString(const char *str) {
  while (*str) {
    USARTPutChar(*str++);
  }
}


ISR(INT0_vect) {
  static int btnCounter = 0;
  static bool wasPressed = false;

  if (counter < btnCounter + 5) {
    return;
  }

  bool isPressed = bit_is_clear(PIND, btnPin); // button is high when not pressed

  if (wasPressed && !isPressed) {
    enum BtnPressType pressType =  counter - btnCounter > 15 ? LONG_PRESS : SHORT_PRESS;
    char buffer[40];
    snprintf(buffer, sizeof(buffer), "pressType=%d\r\n", pressType);
    printUSARTString(buffer);
  }

  btnCounter = counter;
  wasPressed = isPressed;
}

ISR(TIMER0_OVF_vect) {
  counter++;
}

void setup(void);
void setupButtons(void);

int main(void) {
  setup();
  USARTInit(9600);

  while (1);
}

void setup(void) {
  setupButtons();
}

void setupButtons(void) {
  DDRD &= ~_BV(btnPin);
  PORTD |= _BV(btnPin);

  // External Interrupt INT0
  EIMSK |= _BV(INT0);
  EICRA |= _BV(ISC00);

  // Timer 0, 1024 prescaler, normal mode, 8-bit
  TIMSK0 |= (1 << TOIE0);
  TCCR0B |= (1 << CS02) | (1 << CS00);

  sei();
}