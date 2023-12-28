#include <avr/io.h>
#include "uart.h"

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

void usart_print_string(const char *str) {
  while (*str) {
    usart_put_char(*str++);
  }
}