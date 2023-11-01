CC=avr-gcc
CFLAGS= -Os -DF_CPU=16000000UL -mmcu=atmega328p

# Default target
all: button.out

USBPORT=$(shell ls /dev/tty.usbmodem*)

# $< - means input file (%.c)
# $a - means target file (%.out)
# %.out and %.c - mask for any file ending with   
%.out: projects/%.c
	$(CC) $(CFLAGS) $< -o $@

%.hex: %.out
	avr-objcopy -O ihex -R .eeprom $< $@

install.%: %.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P ${USBPORT} -b 115200 -U flash:w:$<

clean:
	rm -f *.hex *.o