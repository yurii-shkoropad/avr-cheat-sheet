# General

## Serial Port
When flashing firmware, need to specify serial port on which micro controller is connected:
- Windows - `COM3`;
- Linux - `/dev/ttyUSB0`;
- MacOS - `/dev/tty.usbmodem1421` or `/dev/tty.usbserial-2110`. On MacOs can be found with `ls /dev/tty.usb*`;

### USB UART Driver
CP210x USB to UART Bridge VCP Drivers from Silabs [link](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads#software)

## Baud rate 
Baud rate - at which speed firmware will be flashed. Different micro controllers has different baud rates. 
- `ATMEGA328P` - 115200;
- `NodeMCU LoLin` - 9600;

## MCU
Short for microcontroller

## SoC
System-on-a-chip - integrated circuit that integrates most or all components of a computer or other electronic system.

## Bit numbering
LSB - least significant bit.

![lsb](./assets/lsb.png)

MSB - most significant bit.

![msb](./assets/msb.png)


## DIP
Dual In-line Package is an electronic component package with a rectangular housing and two parallel rows of electrical connecting pins.

![dip](assets/dip.jpeg)

### Pin numbering
Pin numbering is counter-clockwise. Notch in the package is at the top.

![dip numbering](assets/dip-numbpering.png)