# External Interrupts
The external interrupts are triggered by the INT0 and INT1 pins or any of the PCINT23..0 pins when a pin changes its logical state. Observe that, if enabled, the interrupts will trigger even if the INT0 and INT1 or PCINT23..0 pins are configured as outputs. 

## Pins
| Arduino pin | Atmega328P | INT  | PCINT   | PCMSK  |
| ----------- | ---------- | ---- | ------- | ------ |
| D2          | PD2        | INT0 | PCINT18 | PCMSK2 |
| D3          | PD3        | INT0 | PCINT19 | PCMSK2 |
| D4          | PD4        |      | PCINT20 | PCMSK2 |
| D5          | PD5        |      | PCINT21 | PCMSK2 |
| D6          | PD6        |      | PCINT22 | PCMSK2 |
| D7          | PD7        |      | PCINT23 | PCMSK2 |
| D8          | PB0        |      | PCINT0  | PCMSK0 |
| D9          | PB1        |      | PCINT1  | PCMSK0 |
| D10         | PB2        |      | PCINT2  | PCMSK0 |
| D11         | PB3        |      | PCINT3  | PCMSK0 |
| D12         | PB4        |      | PCINT4  | PCMSK0 |
| D13         | PB5        |      | PCINT5  | PCMSK0 |

## Vectors
- `INT0_vect` - INT interrupt for `INT0`
- `INT1_vect` - INT interrupt for `INT1`
- `PCINT0_vect` - PCI interrupt for `PCINT0`
- `PCINT1_vect` - PCI interrupt for `PCINT1`
- `PCINT2_vect` - PCI interrupt for `PCINT2`

## Registers
- `EICRA` – External Interrupt Control Register A. Used for configuration `INT0` and `INT1`.
- `EIMSK` – External Interrupt Mask Register. Used for enabling/disabling `INT0` and `INT1`.
- `PCMSK0` - Pin Change Mask Register 0. Used for enabling/disabling `PCINT` pins on `PCI0`.
- `PCMSK1` - Pin Change Mask Register 1. Used for enabling/disabling `PCINT` pins on `PCI1`.
- `PCMSK2` - Pin Change Mask Register 2. Used for enabling/disabling `PCINT` pins on `PCI2`.
- `PCICR` – Pin Change Interrupt Control Register. Used for enabling/disabling `PCI0`, `PCI1` or `PCI2`.

## INT Interrupts
These interrupts are triggered by a change in the state of the corresponding pin (rising or falling edge, or low level, depending on the configuration). `Atmega328P` has two `INT0` and `INT1` INT interrupts.

- `INT0` - `PD2`;
- `INT1` - `PD3`;

### Modes
Use `EICRA` register to set `INT` interrupts.

For `INT0` 
| ISC01 | ISC00 | Description                                                |
| ----- | ----- | ---------------------------------------------------------- |
| 0     | 0     | The low level of INT1 generates an interrupt request.      |
| 0     | 1     | Any logical change on INT1 generates an interrupt request. |
| 1     | 0     | The falling edge of INT1 generates an interrupt request.   |
| 1     | 1     | The rising edge of INT1 generates an interrupt request.    |

For `INT1` 
| ISC11 | ISC10 | Description                                                |
| ----- | ----- | ---------------------------------------------------------- |
| 0     | 0     | The low level of INT1 generates an interrupt request.      |
| 0     | 1     | Any logical change on INT1 generates an interrupt request. |
| 1     | 0     | The falling edge of INT1 generates an interrupt request.   |
| 1     | 1     | The rising edge of INT1 generates an interrupt request.    |

### Example 
Example of INT0 interrupt on falling edge
```c
#include <avr/interrupt.h>
#include <avr/io.h>

const int int0Pin = PD2;

// Interrupt Service Routine (ISR) for INT0
ISR(INT0_vect) {
  // will run on interrupt
}

void setupExternalInterrupt(void);

int main(void) {
  setupExternalInterrupt();

  DDRD &= ~(1 << int0Pin); // Read mode
  PORTD |= 1 << int0Pin; // Pull up resistor

  while (1);
}

void setupExternalInterrupt(void) {
  EIMSK |= 1 << INT0; // Enable INT0
  EICRA |= 1 << ISC01; // Set INT0 interruptions on falling edge

  // EICRA |= _BV(ISC01) | _BV(ISC01); // Set INT0 interruptions on rising edge

  sei();
} 
```

## PCI Interrupts (Pin Change interrupt)
The pin change interrupt will trigger if any enabled pin toggles. Cannot specify if trigger on rising of falling edge.
`Atmega328P` has three `PCI0`, `PCI1`, `PCI2` PCI interrupts.

### Example
Example of PCINT0 (PCMSK0) interrupt on any state change
```c
#include <avr/interrupt.h>
#include <avr/io.h>

const int pciPin = PB0;

// Interrupt Service Routine (ISR) for INT0
ISR(PCINT0_vect) {
  // will run on interrupt
}

void setupExternalInterrupt(void);

int main(void) {
  setupExternalInterrupt();

  DDRB &= ~(_BV(pciPin)); // Read mode
  PORTB |= _BV(pciPin); // Pull up resistor

  while (1);
}

void setupExternalInterrupt(void) {
  PCICR = (1 << PCIE0); // Enable PCI0
  PCMSK0 |= _BV(PCINT0); // Enable PCINT0 (D8/PB0) on PCI0

  sei();
} 
```


