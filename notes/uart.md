# UART

Perfect video which explains UART protocol [link](https://www.youtube.com/watch?v=sTHckUyxwp8)

## Connect to serial

### VSCode serial monitor extension
[link](https://marketplace.visualstudio.com/items?itemName=ms-vscode.vscode-serial-monitor)

### Using screen tool
`$ ls /dev/cu.*` - find device

`$ screen -ls` - list all sessions

`$ screen /dev/cu.usbserial-XXXX 9600` - attach session to device

`CTRL+A → CTRL+K` - stop session


## USART
Code example

```c
#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 16000000
#endif

void USARTInit(uint32_t baud);
void USARTPutChar(uint8_t data);
void printUSARTString(const char *str);

int main(void) {
  USARTInit(9600);
  printUSARTString("Hello from USART!!\r\n");

  while (1);
}

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
```