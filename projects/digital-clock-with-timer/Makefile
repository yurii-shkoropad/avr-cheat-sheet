CC=avr-gcc
CFLAGS= -Os -DF_CPU=16000000UL -mmcu=atmega328p
LIBS=./src/spi.c ./src/max7219.c

# Default target
all: main.out

USBPORT=$(shell ls /dev/tty.usb*)
BAUD_RATE=57600 # Nano
# BAUD_RATE=115200 # UNO

# $< - means input file (%.c)
# $a - means target file (%.out)
# %.out and %.c - mask for any file ending with   
%.out: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

%.hex: %.out
	avr-objcopy -O ihex -R .eeprom $< $@

install.%: %.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P ${USBPORT} -b ${BAUD_RATE} -U flash:w:$<

clean:
	rm -f *.hex *.o