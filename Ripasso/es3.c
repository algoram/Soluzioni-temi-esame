#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

int stessaIniziale(char testo[]);
int valido(char carattere);

int main() {
    char testo[] = "caccaABCcacca cazzo";

    int risultato = stessaIniziale(testo);

    if (risultato) {
        printf("Tutte le parole hanno la stessa iniziale\n");
    } else {
        printf("Le parole non hanno la stessa iniziale\n");
    }

    return 0;
}

/*
testo: "caccaABCdacca"
*/

int stessaIniziale(char testo[]) {
    int parola = 0;
    int i;
    char iniziale = '\0';

    for (i = 0; testo[i] != '\0'; i++) {
        int val = valido(testo[i]);

        if (val && parola == 0) {
            if (iniziale == '\0') {
                iniziale = testo[i];
            } else if (testo[i] != iniziale) {
                return 0;
            }

            parola = 1;
        } else if (val == 0) {
            parola = 0;
        }
    }

    return 1;
}

int valido(char carattere) {
    if (carattere >= 'a' && carattere <= 'z') {
        return 1;
    }

    return 0;
}
