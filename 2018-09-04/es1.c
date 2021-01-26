#include <stdio.h>

#define CIFRE 23

void mantissa(float f);

int main() {
  float f = 0.125;

  mantissa(f);

  return 0;
}

void mantissa(float f) {
  int i;

  for (i = 0; i < CIFRE; i++) {
    f *= 2;

    if (f >= 1.0) {
      printf("1");
      f -= 1.0;
    } else {
      printf("0");
    }
  }
}