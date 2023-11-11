#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>

const int downBtnPin = PB0;
const int upBtnPin = PB1;
const int ledPin = PB2;

void setupPins(void);
void setupBtnInterrupts(void);
void setupTimer(void);

volatile bool downBtnWasPressed = false;
volatile bool upBtnWasPressed = false;
volatile int count = 0;
volatile int btnCounter = 0;

// Interrupt Service Routine (ISR) for INT0
ISR(PCINT0_vect) {
  bool downBtnPressed = bit_is_clear(PINB, downBtnPin);
  bool upBtnPressed = bit_is_clear(PINB, upBtnPin);

  if ((upBtnPressed != upBtnWasPressed || downBtnPressed != downBtnWasPressed) 
    && (count < (btnCounter + 4))) {
    return;
  }

  if (!upBtnPressed && upBtnWasPressed) {
    PORTB ^= _BV(ledPin);
  }

  if (!downBtnPressed && downBtnWasPressed) {
    PORTB ^= _BV(ledPin);
  }

  downBtnWasPressed = downBtnPressed;
  upBtnWasPressed = upBtnPressed;
  btnCounter = count;
}

ISR(TIMER0_OVF_vect) {
  count++;
}

void setupExternalInterrupt(void);

int main(void) {
  setupPins();
  setupBtnInterrupts();
  setupTimer();

  sei();

  while (1);
}

void setupPins(void) {
  DDRB |= _BV(ledPin);
  DDRB &= ~(_BV(downBtnPin) | _BV(upBtnPin));

  PORTB |= _BV(downBtnPin) | _BV(upBtnPin); // Internal pull up resistor
}

void setupBtnInterrupts(void) {
  PCICR = (1 << PCIE0); // Enable PCI0
  PCMSK0 |= _BV(PCINT0) | _BV(PCINT1); // Enable PCINT0 (D8/PB0) and (D9/PB1) on PCI0
} 

void setupTimer(void) {
  TIMSK0 |= (1 << TOIE0); // timer 0 normal mode (8 bit)
  TCCR0B |= (1 << CS02) | (1 << CS00); // Set prescaler to 1024
}