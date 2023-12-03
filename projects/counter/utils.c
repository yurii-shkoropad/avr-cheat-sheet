#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>

enum BtnPressType {
  NOT_PRESSED,
  SHORT_PRESS,
  LONG_PRESS
};

volatile int msCounter = 0;

const uint8_t dataPin = PB3; // PICO, MOSI
const uint8_t sckPin = PB5; // Serial clock
const uint8_t latchPin = PB2; 

const uint8_t numbers[] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

ISR(TIMER0_OVF_vect) {
  msCounter++;
}

void SPI_MasterTransmit(uint8_t data) {
  SPDR = data;
  while(bit_is_clear(SPSR, SPIF));
}

void drawDisplay(uint8_t data) {
  uint8_t l = data / 10;
  uint8_t r = (data % 10);

  SPI_MasterTransmit(numbers[r]);// 7 segment with common anode, LSB
  SPI_MasterTransmit(numbers[l]); 

  PORTB |= _BV(latchPin);
  _delay_us(1);
  PORTB &= ~_BV(latchPin);
  _delay_us(1);
}

void setupSPI(void) {
  DDRB |= _BV(dataPin) | _BV(sckPin) | _BV(latchPin);

  SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI, MSTR - MOSI, fck/16
}

void setupTimer(void) {
    // Timer 0, 1024 prescaler, normal mode, 8-bit
  TIMSK0 |= (1 << TOIE0);
  TCCR0B |= (1 << CS02) | (1 << CS00);

  sei();
}

void setupButton(uint8_t btnPin) {
  DDRD &= ~_BV(btnPin);
  PORTD |= _BV(btnPin);

  // External Interrupt INT0
  EIMSK |= _BV(INT0);
  EICRA |= _BV(ISC00);
}

enum BtnPressType detectButton(uint8_t btnPin) {
  static int btnCounter = 0;
  static bool wasPressed = false;

  bool isPressed = bit_is_clear(PIND, btnPin); // button is high when not pressed

  if (msCounter < (btnCounter + 5)) {
    return NOT_PRESSED;
  }

  enum BtnPressType pressType = NOT_PRESSED;
  if (wasPressed && !isPressed) {
    pressType =  msCounter - btnCounter > 50 ? LONG_PRESS : SHORT_PRESS;
    return pressType;
  }

  btnCounter = msCounter;
  wasPressed = isPressed;

  return pressType;
}