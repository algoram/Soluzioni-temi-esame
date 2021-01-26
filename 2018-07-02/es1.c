#include <stdio.h>

#define MAX 1000

int MassimaCrescente(int array[], int lung);

int main() {
  int array[MAX] = {3, 2, 4, 6, 1, 3, 2, 4, 6, 7, 9, 3, 2};
  int lung = 13;
  int indice, i;

  indice = MassimaCrescente(array, lung);

  printf("[%d", array[indice]);
  i = indice + 1;
  while (i < lung && array[i] > array[i - 1]) {
    printf(", %d", array[i]);
    i++;
  }
  printf("]\n");

  return 0;
}

int MassimaCrescente(int array[], int lung) {
  int max, indiceMax;
  int indice;
  int len;
  int i;

  indiceMax = -1;
  max = 1;
  indice = 0;
  len = 1;
  i = 1;

  while (i < lung) {
    if (array[i] > array[i - 1]) {
      if (len == 1) {
        indice = i - 1;
      }

      len++;
    } else {
      if (len > max) {
        max = len;
        indiceMax = indice;
      }

      len = 1;
    }

    i++;
  }

  if (len > max) {
    max = len;
    indiceMax = indice;
  }

  return indiceMax;
}