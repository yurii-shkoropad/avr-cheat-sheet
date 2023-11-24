# General

## Serial Port
When flashing firmware, need to specify serial port on which micro controller is connected:
- Windows - `COM3`;
- Linux - `/dev/ttyUSB0`;
- MacOS - `/dev/tty.usbmodem1421` or `/dev/tty.usbserial-2110`. On MacOs can be found with `ls /dev/tty.usb*`;

### USB UART Driver
CP210x USB to UART Bridge VCP Drivers from Silabs [link](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads#software)

## Baud rate 
Baud rate - at which speed firmware will be flashed. Different micro controllers has different baud rates. 
- `ATMEGA328P` - 115200;
- `NodeMCU LoLin` - 9600;

## MCU
Short for microcontroller

## SoC
System-on-a-chip - integrated circuit that integrates most or all components of a computer or other electronic system.

## Bit numbering
LSB - least significant bit.

![lsb](./assets/lsb.png)

MSB - most significant bit.

![msb](./assets/msb.png)


## DIP
Dual In-line Package is an electronic component package with a rectangular housing and two parallel rows of electrical connecting pins.

![dip](assets/dip.jpeg)

### Pin numbering
Pin numbering is counter-clockwise. Notch in the package is at the top.

![dip numbering](assets/dip-numbpering.png)

## C Notes
- `volatile` - keyword to specify do not optimize variable. Useful with interrupts. Example `volatile uint8_t bcdCounter = 0;`
- `snprintf` - defined in `<stdio.h>`,  formats and stores a series of characters and values in the array buffer. Useful to get string with integer. Example:
```c
  char buffer[30];
  snprintf(buffer, sizeof(buffer), "i=%d\r\n", i);
  printUSARTString(buffer);
```

### Specifiers
| Specifier | Used for                                           |
| --------- | -------------------------------------------------- |
| %c        | a single character                                 |
| %s        | a string                                           |
| %hi       | short (signed)                                     |
| %hu       | short (unsigned)                                   |
| %Lf       | long double                                        |
| %n        | prints nothing                                     |
| %d        | a decimal integer (assumes base 10)                |
| %i        | a decimal integer (detects the base automatically) |
| %o        | an octal (base 8) integer                          |
| %x        | a hexadecimal (base 16) integer                    |
| %p        | an address (or pointer)                            |
| %f        | a floating point number for floats                 |
| %u        | int unsigned decimal                               |
| %e        | a floating point number in scientific notation     |
| %E        | a floating point number in scientific notation     |
| %%        | the % symbol                                       |