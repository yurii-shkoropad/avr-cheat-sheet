# Arduino uno

It uses [atmega328p](./atmega-328p.md) under the hood.

## Pinout

| Arduino pin | Atmega328P | Additional Functions |
| --- | --- | --- |
| D2 | PD2 ||
| D3 | PD3 ||
| D4 | PD4 ||
| D5 | PD5 ||
| D6 | PD6 ||
| D7 | PD7 ||
| D8 | PB0 ||
| D9 | PB1 ||
| D10 | PB2 ||
| D11 | PB3 ||
| D12 | PB4 ||
| D13 | PB5 |Builtin Led|

![Pinout uno](/assets//pinout-uno.png)

## Pull up resistor

All pins has pull up resistors (need to set `DDRxn` low (input mode) and `PORTxn` high)