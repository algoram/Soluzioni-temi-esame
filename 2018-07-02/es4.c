#include <stdio.h>

typedef struct tessera {
  int parte1;
  int parte2;
} Tessera;

int main(int argc, char** argv) {
  FILE* file;
  Tessera t1, t2;
  int catena;

  file = fopen(argv[1], "r");

  catena = 1;
  fscanf(file, "(%d,%d)", &(t1.parte1), &(t1.parte2));
  while (catena && fscanf(file, "(%d,%d)", &(t2.parte1), &(t2.parte2)) == 2) {
    if (t2.parte1 != t1.parte2) {
      catena = 0;
    } else {
      t1.parte1 = t2.parte1;
      t1.parte2 = t2.parte2;
    }
  }

  if (catena) {
    printf("La sequenza e' una catena\n");
  } else {
    printf("La sequenza non e' una catena\n");
  }

  return 0;
}