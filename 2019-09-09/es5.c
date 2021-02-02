#include <stdio.h>
#include <stdlib.h>

#define MAX 52

typedef struct carta {
  int valore;
  int seme;
} Carta;

int indiceCarta(Carta c);

int main() {
  FILE* file;
  int occorrenze[MAX];
  int i;
  Carta c;
  int completo;

  file = fopen("carte.txt", "r");

  if (file) {
    for (i = 0; i < MAX; i++) {
      occorrenze[i] = 0;
    }

    while (fscanf(file, "(%d,%d)", &(c.valore), &(c.seme)) == 2) {
      printf("(%d,%d)\n", c.valore, c.seme);
      occorrenze[indiceCarta(c)]++;
    }

    fclose(file);

    completo = 1;
    for (i = 0; i < MAX; i++) {
      if (occorrenze[i] != 1) {
        completo = 0;
      }
    }

    if (completo) {
      printf("Il mazzo di carte e' completo\n");
    } else {
      printf("Il mazzo di carte non e' completo\n");
    }
  } else {
    printf("Errore nell'apertura del file\n");
  }

  return 0;
}

int indiceCarta(Carta c) {
  int indice = (c.seme - 1) * 13 + (c.valore - 1);

  return indice;
}