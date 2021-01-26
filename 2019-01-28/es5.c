#include <stdio.h>

#define MAX 1000

int main(int argc, char** argv) {
  FILE* file = fopen(argv[1], "r");
  int preproc, commenti, istruz, utili;
  char linea[MAX + 1];
  int i;

  preproc = 0;
  commenti = 0;
  istruz = 0;
  utili = 0;

  fgets(linea, MAX, file);
  while (!feof(file)) {
    i = 0;
    // salto gli spazi iniziali
    while (linea[i] == ' ') i++;

    // controllo il primo carattere utile
    if (linea[i] == '/') {
      // commento
      commenti++;
      utili++;
      i++;
    } else if (linea[i] == '#') {
      // direttiva del preprocessore
      preproc++;
      utili++;
      i++;
    } else if (linea[i] != '\n') {
      // istruzioni, linea non vuota
      istruz++;
      utili++;
    }

    // conto gli ultimi caratteri utili
    while (linea[i] != '\n') {
      utili++;
      i++;
    }

    fgets(linea, MAX, file);
  }

  printf("Linee contenenti direttive del preprocessore: %d\n", preproc);
  printf("Linee contenenti commenti: %d\n", commenti);
  printf("Linee contenenti istruzioni: %d\n", istruz);
  printf("Numero di caratteri utili: %d\n", utili);

  return 0;
}