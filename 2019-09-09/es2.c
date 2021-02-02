#include <stdio.h>

int stessaIniziale(char testo[]);

int main() {
  if (stessaIniziale("ciao Cacca")) {
    printf("Le parole nel testo hanno la stessa iniziale\n");
  } else {
    printf("Le parole nel testo non hanno la stessa iniziale\n");
  }

  return 0;
}

int stessaIniziale(char testo[]) {
  int parola;
  char iniziale;
  int i;

  parola = 0;
  iniziale = EOF;

  for (i = 0; testo[i] != '\0'; i++) {
    if (testo[i] >= 'a' && testo[i] <= 'z') {
      if (parola == 0) {
        if (iniziale == EOF) {
          iniziale = testo[i];
        } else if (testo[i] != iniziale) {
          return 0;
        }
      }

      parola = 1;
    } else {
      parola = 0;
    }
  }

  return 1;
}