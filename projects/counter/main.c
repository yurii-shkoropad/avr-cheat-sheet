#include <avr/io.h>
#include "utils.c"

const int btnPin = PD2;
volatile int counter = 0;

void setup(void);

ISR(INT0_vect) {
  enum BtnPressType btnPress = detectButton(btnPin);

  if (btnPress == LONG_PRESS) {
    counter = 0;
  } else if (btnPress == SHORT_PRESS) {
    counter++;

    if (counter > 99) {
      counter = 0;
    }
  }

  drawDisplay(counter);
}

int main(void) {
  setup();

  drawDisplay(00);

  while (1);
}

void setup(void) {
  setupSPI();
  setupTimer();
  setupButton(btnPin);
}

