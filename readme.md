# AVR Cheat sheet

## Required tools
AVR Toolchain includes ```avr-gcc```, ```avr-objcopy``` and ```avrdude```:

- ```avr-gcc``` - compiles from ```%.c → %.out```
- ```avr-objcopy``` - compiles ```%.out → %.hex```
- ```avrdude``` - flashes firmware ```%.hex``` file to usb port


### Installation

#### Windows
For ```Windows``` download from here [link](https://www.microchip.com/en-us/tools-resources/develop/microchip-studio/gcc-compilers)

#### MacOS
For ```MacOS``` download with custom ```brew``` package [homebrew-avr](https://github.com/osx-cross/homebrew-avr) and ```avr-dude``` separately [here](https://formulae.brew.sh/formula/avrdude).

Use next commands:

```console
$ brew tap osx-cross/avr
$ brew install avr-gcc
$ brew install avrdude
```


### Linux

```console
$ sudo apt-get install gcc-avr avr-libc avrdude
```