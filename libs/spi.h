#include <stdio.h>

#ifndef SPI_H
#define SPI_H

#define DATA_PIN PB3
#define SCK_PIN PB5
#define LATCH_PIN PB2

void init_spi(void);
void spi_transmit(uint8_t data);
void spi_latch(void);

#endif