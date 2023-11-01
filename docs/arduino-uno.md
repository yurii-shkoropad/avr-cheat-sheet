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

![Pinout uno](/assets/pinout-uno.png)

## Pull up resistor

All pins has pull up resistors (need to set pin as input mode and set high value)

## Powering

More details [here](https://docs.arduino.cc/learn/electronics/power-pins)

### USB Connector

Uno has usb connector type A/B

![USB A/B](/assets/usb-ab.jpeg)

Can be powered:
- from laptop;
- from power bank;

## Built-in LED

Arduino has built-in led on PIN 13 (PB5)

![Built-in led](../assets/built-in-led.jpg)