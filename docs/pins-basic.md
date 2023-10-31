# Pins basic

## Access to pin bit
`Pxn` - access to port `x` of  `n` pin bit.

For example
`PD5` - pin 5 of port `D`;
`PB2` - pin 2 of port `B`;

## Working with registers
Register usually are 8 bits. So there are several way how to set and access them.

- Update all with binary. `DDRD = 0b00000000;` - set all 8 bits zero. `DDRD = 0b00000100;` - set all zeros, except 3rd bit as 1;
- Update all with hexadecimal. `DDRD = 0x00;` - set all 8 bits zero. `DDRD = 0xff;` - set all bits as 1s;
- Set `1` value to `1` bit. `DDRD |= 1 << PD5;` - set bit 5 (`PD5` pin 5 of port D) to `1`, other bits unchanged. `DDRD |= (1 << PD5) | (1 << PD4);` - set multiply at once;
- Set `0` value to `1` bit. `DDRD &= ~(1 << PD5);` - set bit 5 (`PD5` pin 5 of port D) to `0`, other bits unchanged. `DDRD &= ~(1 << PD5 | 1 << PD4);` - set multiply at once;
- Toggle value at `1` bit. `DDRD ^= 1 << PD5;` - toggle bit 5 (`PD5` pin 5 of port D), other bits unchanged. `DDRD ^= (1 << PD5) | (1 << PD4);` - toggle multiply at once;
- Read `1` bit value. `PINB & (1 << PB4)` - return bit value (`PB4` - pin 4 of port B);
- Read inverted `1` bit value. `!(PINB & (1 << PB4))` - return inverted bit value (`PB4` - pin 4 of port B);

## Pin Registers

### Data Direction Register
`DDRx` - Data Direction Register, `1` - output, `0` - input.`x` - port `B`, `D` or `C`.

For example:
`DDRD |= 1 << PD5;` - set only `PD5` as output on port `D`;
`DDRD &= ~(1 << PD5);` - set only `PD5` as input on port `D`;
`DDRB = 0x00` - set all as inputs on port `B`;
`DDRB = 0xff` - set all as outputs on port `B`;
 
### Pin output (write)
`PORTx` - PORT output register. Set output as high `1` or low `0`.`x` - port `B`, `D` or `C`.

For example:
`PORTD |= 1 << PD5;` - set only `PD5` to value `1` (high) on port `D`;
`PORTD &= ~(1 << PD5);` - set only `PD5` to value `0` (low) on port `D`;
`PORTB = 0x00` - set all as inputs as `0`s (low) on port `B`;
`PORTB = 0xff` - set all as inputs as `1`s (high) on port `B`;


### Pin input (read)
`PINx` - PIN input register. Read value on pin. `1` - high, `0` - low.`x` - port `B`, `D` or `C`.

For example:
`(PIND >> PD5) & 1;` - read `PD5` value on port `D`;
`!((PIND >> PD5) & 1);` - read inverted `PD5` value on port `D`;