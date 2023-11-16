# Micropython
[link](https://micropython.org/download/)

## ESPTool
Utility to communicate with the ROM bootloader in Espressif SoCs.

Official documentation [link](https://docs.espressif.com/projects/esptool/en)

### Commands
- `esptool.py -p PORT flash_id` - check connected device. On macos you can run `esptool.py -p $(ls /dev/tty.usb*) flash_id` for autodetect port;
- `esptool.py -p PORT erase_flash` - erase the flash;
- `esptool.py -p /dev/tty.usbserial-2110 --baud 460800 write_flash --flash_size=detect 0 ESP8266_GENERIC-20231005-v1.21.0.bin` - write firmware. NodeMcu will fail with option `baud 9600`;


## Rshell
Remote shell
[link](https://github.com/dhylands/rshell)

- `rshell -p /dev/tty.usbserial-2110` - connect to `rshell`;
- `CTRL+X` - exit repl in `rshell`;


### NOTE
The esp8266 doesn't have `/flash`. It makes the internal flash filesystem be at root /. There is an alternative in that you can use `/pyboard` to reference the root filesystem of the first connected board.