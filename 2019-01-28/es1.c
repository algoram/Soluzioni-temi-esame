#include <stdio.h>

#define CIFRE 23

void mantissa(float f, int array[]);

int main() {
  float f = 0.0625;
  int array[CIFRE];
  int i;

  mantissa(f, array);

  for (i = 0; i < CIFRE; i++) {
    printf("%d", array[i]);
  }
  printf("\n");

  return 0;
}

void mantissa(float f, int array[]) {
  int i;

  for (i = 0; i < CIFRE; i++) {
    f *= 2;

    if (f >= 1.0) {
      array[i] = 1;
      f -= 1.0;
    } else {
      array[i] = 0;
    }
  }
}