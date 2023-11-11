# 4 pin button
4 Pin Button has 4 pins. 

![button](/assets/button.jpg)

# How it works
Two pins on left connected, and two right connected when button is unpressed.
When button is pressed left and right pins are connected.

![button-connection](/assets/button-connection.png)

## Floating Inputs
When a digital input is left unconnected or is in a high-impedance state, it can "float" and pick up electrical noise. A pull-up or pull-down resistor provides a defined voltage level to ensure that the input is in a known state, either logic high or logic low.

### Pull-up resistor
Pull-up resistor ensures that the signal line remains at a known logic level when it's not being actively driven, a pull-up resistor is connected between the signal line and the supply voltage (usually Vcc). The pull-up resistor pulls the line to the logic high state (usually 1 or Vcc) when it's not being actively pulled low by the device. Resistor value 4.7 kOm is perfect, but any from 1kOm to 10kOm will work.

So when button is not pressed, PIN will have 1, if pressed - 0.

![button pull up](/assets/button-pull-up.svg)


### Pull-down resistor
Pull-down resistors work in the same manner as pull-up resistors, except that they pull the pin to a logical low value.
Resistor value 4.7 kOm is perfect, but any from 1kOm to 10kOm will work. 

So when button is not pressed, PIN will have 0, if pressed - 1.

![button pull down](/assets/button-pull-down.svg)

### Internal pull-up resistor
Atmega328P micro controller (on Arduino UNO board) has built-in internal pull up resistor. To activate it, setup PIN in output mode and set value 1 on pin. For example:

```c
DDRB &= ~(1 << PB0);
PORTB |= 1 << PB0;
```

So when button is not pressed, PIN will have 1, if pressed - 0.

![button pull up internal](/assets/button-internal-pull-up.svg)

## Debounce button
Push buttons often generate spurious open/close transitions when pressed, due to mechanical and physical issues: these transitions may be read as multiple presses in a very short time fooling the program.

### Hardware debounce 
The combination of a resistor and capacitor in this circuit is referred to as an RC filter. RC filters can be used to filter out different frequencies of electrical variation.

Calculator for capacitor value [link](https://protological.com/debounce-calaculator/).
100uF and 1kOm should be fine.

So when button is not pressed, PIN will have 1, if pressed - 0.

![button capacitor debounce](/assets/button-capacitor-debounce.svg)

### Software debounce
TODO

## Schematic symbol

![button symbol](/assets/button-symbol.png)

