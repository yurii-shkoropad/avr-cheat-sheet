#include <avr/io.h>

#ifndef UART_H
#define UART_H

#ifndef F_CPU
#define F_CPU 16000000
#endif

void usart_init(uint32_t baud);
void usart_put_char(uint8_t data);
void usart_print_string(const char *str);

#endif