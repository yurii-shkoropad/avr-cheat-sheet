#include "max7219.h"
#include "spi.h"

void max7219_send(uint8_t addr, uint8_t data) {
  spi_transmit(addr);
  spi_transmit(data);

  spi_latch();
}

void max7219_init() {
  max7219_send(MAX7219_SCAN_LIMIT_REG, 0xf);
  max7219_send(MAX7219_DISPLAY_TEST_REG, 0);
  max7219_send(MAX7219_INTENSITY_REG, 0x02);
  max7219_send(MAX7219_DECODE_MODE_REG, 0xff);
  max7219_send(MAX7219_SHUTDOWN_REG, 1);

  max7219_send(0x01, 0);
  max7219_send(0x02, 0);
  max7219_send(0x03, 0);
  max7219_send(0x04, 3);
  max7219_send(0x05, 0);
  max7219_send(0x06, 0);
  max7219_send(0x07, 0);
  max7219_send(0x08, 0);
}
