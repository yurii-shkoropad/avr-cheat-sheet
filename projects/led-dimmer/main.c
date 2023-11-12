#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>

const int downBtnPin = PB0;
const int upBtnPin = PB1;
const int ledPin = PD6;

void setupPins(void);
void setupBtnInterrupts(void);
void setupTimer(void);

volatile bool downBtnWasPressed = false;
volatile bool upBtnWasPressed = false;
volatile int count = 0;
volatile int btnCounter = 0;
volatile int dutyCycleValue = 0;

// Interrupt Service Routine (ISR) for INT0
ISR(PCINT0_vect) {
  bool downBtnPressed = bit_is_clear(PINB, downBtnPin);
  bool upBtnPressed = bit_is_clear(PINB, upBtnPin);

  if ((upBtnPressed != upBtnWasPressed || downBtnPressed != downBtnWasPressed) 
    && (count < (btnCounter + 4))) {
    return;
  }

  if (!upBtnPressed && upBtnWasPressed) {
    dutyCycleValue = dutyCycleValue + 5; 
    if (dutyCycleValue > 255) {
      dutyCycleValue = 255;
    }
  }

  if (!downBtnPressed && downBtnWasPressed) {
    dutyCycleValue = dutyCycleValue - 5; 
    if (dutyCycleValue < 0) {
      dutyCycleValue = 0;
    }
  }

  downBtnWasPressed = downBtnPressed;
  upBtnWasPressed = upBtnPressed;
  btnCounter = count;
  OCR0A = dutyCycleValue;
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
  DDRD |= _BV(ledPin);
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

  TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1); // FAST PWM
  OCR0A = 0;
}