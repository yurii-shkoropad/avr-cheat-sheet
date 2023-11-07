# Interruptions
Interruptions mechanism for handling asynchronous events or signals, typically called interrupts. Interrupts can stop the main program from executing to perform a separate interrupt service routine (ISR)

To access pins and registers to control pins use `<avr/interrupt.h>` library.


## Enabling/Disabling interruptions
Before using interruptions, interruptions should be enabled in `SREG`– AVR Status Register (bit 8). 
It's possible to set bit manually (for example `SREG |= 1 << 7;`), but proffered to use next functions:
- `sei();` - enable interruptions
- `cli();` - disable interruptions

**Use infinite loop!!!**

Interrupts may not work as expected if there is no infinite loop or a mechanism to keep the micro controller running in your program. So even if program doesn't need to have infinite loop, it should be present in order to allow interruptions to work `while (1);`.


## Timer interruptions

## PCI interruption