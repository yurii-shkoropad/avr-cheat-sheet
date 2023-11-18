# Micropython
[link](https://micropython.org/download/)

## ESPTool
Utility to communicate with the ROM bootloader in Espressif SoCs.

Official documentation [link](https://docs.espressif.com/projects/esptool/en)

### Commands
- `esptool.py -p PORT flash_id` - check connected device. On macos you can run `esptool.py -p $(ls /dev/tty.usb*) flash_id` for autodetect port;
- `esptool.py -p PORT erase_flash` - erase the flash;
- `esptool.py -p /dev/tty.usbserial-2110 --baud 460800 write_flash --flash_size=detect 0 ESP8266_GENERIC-20231005-v1.21.0.bin` - write firmware. NodeMcu will fail with option `baud 9600`;
- `esptool.py --chip esp32 --port /dev/tty.usbserial-2140 write_flash -z 0x1000 esp32-20180511-v1.9.4.bin` - write firmware to `esp32`;

## Rshell
Remote shell
[link](https://github.com/dhylands/rshell)

- `rshell -p /dev/tty.usbserial-2110` - connect to `rshell`;
- `CTRL+X` - exit repl in `rshell`;

## mip
Package management. Should be in `REPL` mode;
- `mip install pkgname` - install package remotely;

## mpremote
Docs [link](https://docs.micropython.org/en/latest/reference/mpremote.html#mpremote)
Install with `sudo`;
- `mpremote connect auto` - connected to first serial USB device;
- `mpremote run file.py` - run file on connected board;


### NOTE
The esp8266 doesn't have `/flash`. It makes the internal flash filesystem be at root /. There is an alternative in that you can use `/pyboard` to reference the root filesystem of the first connected board.