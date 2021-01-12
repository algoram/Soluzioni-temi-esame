#include <stdio.h>
#include <string.h>

#define MAX 100
#define PAROLE 100000

/* WORK IN PROGRESS, QUESTO CODICE AL MOMENTO NON VA, PER QUALCHE OSCURO MOTIVO */

typedef char Vocabolario[PAROLE][MAX];

int iniziale(char* a, char* b);
int ricercaBinaria(Vocabolario v, char str[], int inizio, int fine);

int main() {
    Vocabolario v;
    char str[] = "fono";

    strcpy(v[0], "fondo");
    strcpy(v[1], "fonografo");
    strcpy(v[2], "fonoxyz");

    if (ricercaBinaria(v, str, 0, 2)) {
        printf("La stringa e' l'iniziale di almeno una stringa nel vocabolario\n");
    } else {
        printf("La stringa non e' iniziale di nessuna stringa del vocabolario\n");
    }

    return 0;
}

int iniziale(char* a, char* b) {
    if (*a == '\0') return 1;
    if (*b == '\0') return 0;

    fprintf(stderr, "%c %c\n", *a, *b);

    if (*a != *b) return 0;

    return iniziale(a+1, b+1);
}

int ricercaBinaria(Vocabolario v, char str[], int inizio, int fine) {
    int mezzo;

    if (inizio > fine) {
        return 0;
    }

    mezzo = (inizio + fine) / 2;

    if (iniziale(str, v[mezzo])) {
        return 1;
    }

    if (strcmp(str, v[mezzo]) < 0) {
        return ricercaBinaria(v, str, inizio, mezzo - 1);
    }

    return ricercaBinaria(v, str, mezzo + 1, fine);
}
