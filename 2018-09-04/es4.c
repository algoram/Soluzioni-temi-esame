#include <stdio.h>

typedef struct dato {
  int Valore;
  char Chiave;
} Dato;

int main() {
  FILE* file;
  Dato dato;
  Dato primo;
  int trovato;

  file = fopen("Archivio", "r+b");

  if (file) {
    fread(&primo, sizeof(Dato), 1, file);

    dato.Chiave = primo.Chiave;
    dato.Valore = primo.Valore;

    trovato = 0;
    while (!feof(file) && !trovato) {
      if (dato.Chiave == '#') {
        trovato = 1;
      } else {
        fread(&dato, sizeof(Dato), 1, file);
      }
    }

    if (trovato) {
      rewind(file);

      primo.Valore = dato.Valore;

      fwrite(&primo, sizeof(Dato), 1, file);
    }

    if (fclose(file)) {
      printf("Errore nella chiusura del file\n");
    }
  } else {
    printf("Impossibile aprire il file\n");
  }

  return 0;
}