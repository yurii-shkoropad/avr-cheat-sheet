#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

#ifndef F_CPU
#define F_CPU 16000000
#endif

const int btnPin = PD2;
const uint8_t resistorChannel = 0;
const float vcu = 5.0;
const int r1 = 1000;
volatile int msCounter = 0;

void setup(void);
void usart_init(uint32_t baud);
void usart_put_char(uint8_t data);
void print_usart_string(const char *str);
void setup_btn(void);
void setup_timer(void);
void setup_adc(void);
uint16_t adc_read(uint8_t channel);
float adc_read_voltage(uint8_t channel, float Vref);

ISR(INT0_vect) {
  static int btnCounter = 0;

  if (msCounter < (btnCounter + 5)) {
    return;
  }

  btnCounter = msCounter;

  float voltage = adc_read_voltage(resistorChannel, vcu);
  int r2 = (int)((voltage * (float)r1) / (vcu - voltage));

  char buffer[50];
  sprintf(buffer, "r2 resistance=%d, voltage=%2.f\r\n", r2, voltage);

  print_usart_string(buffer);
}

ISR(TIMER0_OVF_vect) {
  msCounter++;
}

int main(void) {
  setup();

  while (1);
}

void setup(void) {
  usart_init(19200);
  setup_btn();
  setup_timer();
  setup_adc();

  sei();
}

void setup_btn(void) {
  DDRD &= ~_BV(btnPin); // Read mode
  PORTD |= _BV(btnPin); // Pull up resistor

  EIMSK |= _BV(INT0); // Enable INT0
  EICRA |= _BV(ISC01) | _BV(ISC00); // Interrupt on falling edge

  sei();
}

void setup_timer(void) {
  TIMSK0 |= (1 << TOIE0);
  TCCR0B |= (1 << CS02) | (1 << CS00);
}

void setup_adc(void) {
  ADMUX |= (1 << REFS0);
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  ADCSRA |= (1 << ADEN);
}

void usart_init(uint32_t baud) {
  UBRR0H = (uint8_t)((F_CPU / (16 * baud) - 1) >> 8);
  UBRR0L = (uint8_t)(F_CPU / (16 * baud) - 1);
  UCSR0A = 0;

  UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
  UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void usart_put_char(uint8_t data) {
  while (!(UCSR0A & (1 << UDRE0)));

  UDR0 = data;
}

void print_usart_string(const char *str) {
  while (*str) {
    usart_put_char(*str++);
  }
}

uint16_t adc_read(uint8_t channel) {
  ADMUX &= 0xF0; 
  ADMUX |= channel;

  ADCSRA |= (1 << ADSC);
  while (bit_is_set(ADCSRA, ADSC));
  uint16_t result = ADCL | (ADCH << 8);

  return result;
}

float adc_read_voltage(uint8_t channel, float Vref) {
  // Read the raw ADC value
  uint16_t ADC_Value = adc_read(channel);

  // ADC Resolution (e.g., 10 bits for most AVR microcontrollers)
  const uint16_t ADC_Resolution = 1023;

  // Convert ADC value to voltage
  float Voltage = (ADC_Value / (float)ADC_Resolution) * Vref;

  return Voltage;
}