CC=avr-gcc
CFLAGS= -Os -DF_CPU=16000000UL -mmcu=atmega328p -Wl,-u,vfprintf -lprintf_flt -lm

# Default target
all: main.out

USBPORT=$(shell ls /dev/tty.usbmodem*)
 
%.out: %.c
	$(CC) $(CFLAGS) $< -o $@

%.hex: %.out
	avr-objcopy -O ihex -R .eeprom $< $@

install.%: %.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P ${USBPORT} -b 115200 -U flash:w:$<

clean:
	rm -f *.hex *.o