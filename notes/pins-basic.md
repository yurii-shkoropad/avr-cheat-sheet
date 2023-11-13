# Pins basic
To access pins and registers to control pins use `avr/io.h` library.

## Access to pin bit
`Pxn` - access to port `x` of  `n` pin bit.

For example
`PD5` - pin 5 of port `D`;
`PB2` - pin 2 of port `B`;

## Working with registers
Register usually are 8 bits. So there are several way how to set and access them.

- `DDRD = 0b00000000;` - set all 8 bits zero with binary;
- `DDRD = 0b00000100;` - set all zeros, except 3rd bit as 1 with binary;
- `DDRD = 0x00;` - set all 8 bits zero with hexadecimal;
- `DDRD = 0xff;` - set all bits as 1s with hexadecimal;
- `DDRD |= 1 << PD5;` - set bit 5 (`PD5` pin 5 of port D) to `1`, other bits unchanged;
- `DDRD |= _BV(PD5);` - set bit 5 (`PD5` pin 5 of port D) to `1`, other bits unchanged using util function;
- `DDRD |= (1 << PD5) | (1 << PD4);` - set multiply at once;
- `DDRD |= _BV(PD5) | _BV(PD4);` - set multiply at once using util function;
- `DDRD &= ~(1 << PD5);` - set bit 5 (`PD5` pin 5 of port D) to `0`, other bits unchanged;
- `DDRD &= ~_BV(PD5);` - set bit 5 (`PD5` pin 5 of port D) to `0`, other bits unchanged using util function;
- `DDRD &= ~(1 << PD5 | 1 << PD4);` - set multiply at once;
- `DDRD &= ~(_BV(PD5) | _BV(PD4));` - set multiply at once using util function;
- `DDRD ^= 1 << PD5;` - toggle bit 5 (`PD5` pin 5 of port D), other bits unchanged;
- `DDRD ^= (1 << PD5) | (1 << PD4);` - toggle multiply at once;
- `PINB & (1 << PB4)` - return bit value (`PB4` - pin 4 of port B);
- `bit_is_set(PINB, PB4);` - return bit value (`PB4` - pin 4 of port B) using util function;
- `!(PINB & (1 << PB4))` - return inverted bit value (`PB4` - pin 4 of port B);
- `bit_is_clear(PINB, PB4);` - return inverted bit value (`PB4` - pin 4 of port B) using util function;

## Pin Registers

### Data Direction Register
`DDRx` - Data Direction Register, `1` - output, `0` - input.`x` - port `B`, `D` or `C`.

For example:
- `DDRD |= 1 << PD5;` - set only `PD5` as output on port `D`;
- `DDRD |= (1 << PD5) | (1 << PD6);` - set `PD5` and `PD6` (others don't change) as output on port `D`;
- `DDRD |= _BV(PD5);` - set only `PD5` as output on port `D` using util function;
- `DDRD |= _BV(PD5) | _BV(PD6);` - set `PD5` and `PD6` (others don't change) as output on port `D` using util function;
- `DDRD &= ~(1 << PD5);` - set only `PD5` as input on port `D`;
- `DDRD &= ~((1 << PD5) | (1 << PD6));` - set `PD5` and `PD6` (others don't change) as input on port `D`;
- `DDRD &= ~_BV(PD5);` - set only `PD5` as input on port `D` using util function;
- `DDRD &= ~(_BV(PD5) | _BV(PD6));` - set `PD5` and `PD6` (others don't change) as input on port `D` using util function;
- `DDRB = 0x00` - set all as inputs on port `B`;
- `DDRB = 0xff` - set all as outputs on port `B`;
 
### Pin output (write)
`PORTx` - PORT output register. Set output as high `1` or low `0`.`x` - port `B`, `D` or `C`.

For example:
- `PORTD |= 1 << PD5;` - set only `PD5` to value `1` (high) on port `D`;
- `PORTD |= _BV(PD5);` - set only `PD5` to value `1` (high) on port `D` using util function;
- `PORTD &= ~(1 << PD5);` - set only `PD5` to value `0` (low) on port `D`;
- `PORTD &= ~_BV(PD5);` - set only `PD5` to value `0` (low) on port `D` using util function;;
- `PORTB = 0x00` - set all as inputs as `0`s (low) on port `B`;
- `PORTB = 0xff` - set all as inputs as `1`s (high) on port `B`;


### Pin input (read)
`PINx` - PIN input register. Read value on pin. `1` - high, `0` - low.`x` - port `B`, `D` or `C`.

For example:
- `(PIND >> PD5) & 1;` - read `PD5` value on port `D`;
- `!((PIND >> PD5) & 1);` - read inverted `PD5` value on port `D`;
- `bit_is_set(PIND, PD5);` - read `PD5` value on port `D` using utils function;
- `bit_is_clear(PIND, PD5);` - read inverted `PD5` value on port `D` using utils function;


## Floating Inputs
When a digital input is left unconnected or is in a high-impedance state, it can "float" and pick up electrical noise. A pull-up or pull-down resistor provides a defined voltage level to ensure that the input is in a known state, either logic high or logic low. 

How to handle this problem, details in [4 pin button](/notes/4-pin-button.md)