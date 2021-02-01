#include <stdio.h>

void stampaIncolonnata(int n);

int main() {
  int n = 365;

  stampaIncolonnata(n);

  return 0;
}

void stampaIncolonnata(int n) {
  if (n == 0) return;

  stampaIncolonnata(n / 10);

  printf("%d\n", n % 10);
}