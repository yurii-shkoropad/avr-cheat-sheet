#include <avr/io.h>
#include <util/delay.h>

const uint8_t ledPin = PD6;
const uint8_t potChannel = 0;

uint16_t ADC_Read(uint8_t channel);
void setup(void);

void setupExternalInterrupt(void);

int main(void) {
  setup();

  USARTInit(9600);

  while(1) {
    float potValue = ADC_Read(potChannel);

    int dutyCycleValue = (int)(255.0 / 1024.0 * potValue);

    OCR0A = dutyCycleValue;

    _delay_ms(50);
  }
}

void setup(void) {
  // Set the voltage reference to AVcc
  ADMUX |= (1 << REFS0);
  // Set the ADC clock prescaler to 128 (ADC frequency = CPU frequency / 128)
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  // Enable the ADC
  ADCSRA |= (1 << ADEN);

  DDRD |= _BV(ledPin);

  TIMSK0 |= (1 << TOIE0); // timer 0 normal mode (8 bit)
  TCCR0B |= (1 << CS02) | (1 << CS00); // Set prescaler to 1024

  TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1); // FAST PWM
}

uint16_t ADC_Read(uint8_t channel) {
  // Clear the channel bits in ADMUX (0b11110000)
  ADMUX &= 0xF0; 
  // Set the new channel in ADMUX
  ADMUX |= channel;

  // Start the conversion
  ADCSRA |= (1 << ADSC);
  // Wait for the conversion to complete
  while (bit_is_set(ADCSRA, ADSC));

  // ADC result is a 10-bit value, so read ADCL and ADCH
  uint16_t result = ADCL | (ADCH << 8);

  return result;
}