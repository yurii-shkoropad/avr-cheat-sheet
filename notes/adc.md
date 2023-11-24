# Analog to Digital Converter (ADC)
Peripheral that allows convert an analog voltage into a digital value.

## Registers
- `ADMUX` – ADC Multiplexer Selection Register. Needed for selecting channel
- `ADCSRA` – ADC Control and Status Register A. Needed to enabling `ADC`, set prescaler (division factor), start conversion


## Division Factor
| ADPS2 | ADPS1 | ADPS0 | Division factor |
| ----- | ----- | ----- | --------------- |
| 0     | 0     | 1     | 2               |
| 0     | 1     | 0     | 4               |
| 0     | 1     | 1     | 8               |
| 1     | 0     | 0     | 16              |
| 1     | 0     | 1     | 32              |
| 1     | 1     | 0     | 64              |
| 1     | 1     | 1     | 128             |

Example
```c
// Set the ADC clock prescaler to 128 (ADC frequency = CPU frequency / 128)
ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
```

## Channel Selection

Example
```c
ADMUX &= 0xF0; // Clear previous selected channel
ADMUX |= 0; // Select A0 channel
ADMUX |= 1; // Select A1 channel
ADMUX |= 2; // Select A2 channel
ADMUX |= 3; // Select A3 channel and etc.
```