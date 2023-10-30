# AVR Cheat sheet

## AVR Toolchain
AVR Toolchain includes `avr-gcc`, `avr-objcopy` and `avrdude`. Details bellow.

### Installation

#### Windows
For `Windows` download from here [link](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio/gcc-compilers)

#### MacOS
For `MacOS` download with custom `brew` package [homebrew-avr](https://github.com/osx-cross/homebrew-avr) and `avr-dude` separately [here](https://formulae.brew.sh/formula/avrdude).

Use next commands:

```console
$ brew tap osx-cross/avr
$ brew install avr-gcc
$ brew install avrdude
```

#### Linux

```console
$ sudo apt-get install gcc-avr avr-libc avrdude
```

### avr-gcc
`avr-gcc` - compiles from `%.c → %.out`.

Flags:
- `-DF_CPU=16000000UL` - target micro controller CPU;
- `-mmcu=atmega328p` - Target micro controller;
- `-Os` - optimization level for the compiler. In this case, `-Os` indicates "optimize for size." It instructs the compiler to prioritize generating smaller code size over faster execution speed;


For example next command will create `test.o` file from `test.c`:

```console
$ avr-gcc Os -DF_CPU=16000000UL -mmcu=atmega328p test.c -o test.out
```

### avr-objcopy
`avr-objcopy` - compiles `%.out → %.hex`

### avrdude
`avrdude` - flashes firmware `%.hex` file to usb port.


#### Serial Port
When flashing firmware, need to specify serial port on which micro controller is connected:
- Windows - `COM3`;
- Linux - `/dev/ttyUSB0`;
- MacOS - `/dev/tty.usbmodem1421` or `/dev/tty.usbserial`;

#### Baud rate 
Baud rate - at which speed firmware will be flashed. Different micro controllers has different baud rates. 
- `ATMEGA328P` - 115200;

Flags:
- `-F` - force;
- `-V` - verbose;
- `-b 115200` - baud rate for communication with the programmer;
- `-p ATMEGA328P` - specify target microcontroller
- `-P /dev/tty.usbmodem1421` - serial port 

For example
```console
$ avrdude -F -V -c arduino -p ATMEGA328P -P /dev/tty.usbmodem1421 -b 115200 -U flash:w:blink.hex
```
