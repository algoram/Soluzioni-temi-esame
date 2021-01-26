#include <stdio.h>

#define MAX 100

typedef struct list {
  int array[100];
  int numElem;
} List;

void Converti(int n, int b, List* l);

int main() {
  int n = 100;
  int b = 16;
  int i;
  List l;

  l.numElem = 0;

  Converti(n, b, &l);

  for (i = 0; i < l.numElem; i++) {
    printf("%d ", l.array[i]);
  }
  printf("\n");

  return 0;
}

void Converti(int n, int b, List* l) {
  int cifra;

  if (n == 0) return;

  cifra = n % b;

  Converti(n / b, b, l);

  l->array[l->numElem++] = cifra;
}