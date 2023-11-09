# External Interrupts
The external interrupts are triggered by the INT0 and INT1 pins or any of the PCINT23..0 pins when a pin changes its logical state. Observe that, if enabled, the interrupts will trigger even if the INT0 and INT1 or PCINT23..0 pins are configured as outputs. 

## INT Interrupts
These interrupts are triggered by a change in the state of the corresponding pin (rising or falling edge, or low level, depending on the configuration).

## PCI Interrupts (Pin Change interrupt)
The pin change interrupt will trigger if any enabled pin toggles o. The pin
change interrupt PCI1 will trigger if any enabled PCINT14..8 pin toggles. The pin change interrupt PCI0 will trigger if any
enabled PCINT7..0 pin toggles. 

