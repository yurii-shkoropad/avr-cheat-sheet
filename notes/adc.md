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

## Example

Code example in `voltage divider scheme`.
```c
#include <avr/io.h>
#include <util/delay.h>

const uint8_t analogPinChannel = 0;
const float vcc = 5.0;

void setup(void);
uint16_t ADC_Read(uint8_t channel);
float ADC_Read_Voltage(uint8_t channel, float Vref);

int main(void) {
  setup();

  while(1) {
    float aValue = ADC_Read_Voltage(analogPinChannel, vcc);

    _delay_ms(1000);
  }
}

void setup(void) {
  // Set the voltage reference to AVcc
  ADMUX |= (1 << REFS0);
  // Set the ADC clock prescaler to 128 (ADC frequency = CPU frequency / 128)
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  // Enable the ADC
  ADCSRA |= (1 << ADEN);
}

uint16_t ADC_Read(uint8_t channel) {
  // Clear the channel bits in ADMUX (0b11110000)
  ADMUX &= 0xF0; 
  // Set the new channel in ADMUX
  ADMUX |= channel;

  // Start the conversion
  ADCSRA |= (1 << ADSC);
  // Wait for the conversion to complete
  while (bit_is_set(ADCSRA, ADSC));

  // ADC result is a 10-bit value, so read ADCL and ADCH
  uint16_t result = ADCL | (ADCH << 8);

  return result;
}

float ADC_Read_Voltage(uint8_t channel, float Vref) {
    // Read the raw ADC value
    uint16_t ADC_Value = ADC_Read(channel);

    // ADC Resolution (e.g., 10 bits for most AVR microcontrollers)
    const uint16_t ADC_Resolution = 1023;

    // Convert ADC value to voltage
    float Voltage = (ADC_Value / (float)ADC_Resolution) * Vref;

    return Voltage;
}
```