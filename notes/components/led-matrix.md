# Led Matrix
Materials used from [lastminuteengineers](https://lastminuteengineers.com/max7219-dot-matrix-arduino-tutorial/)

LED matrixes consist of an array of LEDs arranged in a grid. If this were not the case, an 8×8 dot matrix display would require 65 pins, one for each LED and one for a common anode or common cathode connector. By connecting rows and columns, only 16 pins are needed to control the entire matrix. This technique of controlling a large number of LEDs with fewer pins is referred to as Multiplexing.

## Multiplexing 
Each column is activated for a very short time, and at the same time, the LEDs on that column are lit by addressing the corresponding row. As a result, no more than eight LEDs are lit at the same time. The columns are switched so fast (hundreds or thousands of times per second) that the human eye perceives the display as fully lit.

In this technique, each column is activated for a very short time, and at the same time, the LEDs on that column are lit by addressing the corresponding row. As a result, no more than eight LEDs are lit at the same time. The columns are switched so fast (hundreds or thousands of times per second) that the human eye perceives the display as fully lit.

![led matrix multiplexing](./assets/LED-Matrix-Display-Working-Animation-Persistence-of-Vision.gif)


## 1088AYG
This one has display with a total of 64 LEDs in 8 rows and 8 columns. Green.

Commons cathode (-)

![1088ayg](./assets/1088ayg.jpg)

### Pinout

![1088ayg Pin diagram](./assets/SH1088AS-Pin-Diagram.png)

![1088ayg pinout](./assets/1088AS_pinout.png)