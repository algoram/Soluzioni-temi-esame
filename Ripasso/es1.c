#include <stdio.h>
#include <stdlib.h>

struct el {
    int v;
    struct el* next;
};

struct el* PRIMO = NULL;
struct el* ULTIMO = NULL;
struct el* CENTRALE = NULL;

void Calcolo(struct el* primo, struct el* centrale, int* S1, int* S2);

int main() {
    int S1, S2;

    PRIMO = malloc(sizeof(struct el));
    ULTIMO = malloc(sizeof(struct el));
    CENTRALE = malloc(sizeof(struct el));

    PRIMO->v = 1;
    PRIMO->next = CENTRALE;

    CENTRALE->v = 2;
    CENTRALE->next = ULTIMO;

    ULTIMO->v = 3;
    ULTIMO->next = NULL;

    Calcolo(PRIMO, CENTRALE, &S1, &S2);

    printf("S1: %d, S2: %d\n", S1, S2);

    return 0;
}

void Calcolo(struct el* primo, struct el* centrale, int* S1, int* S2) {
    *S1 = 0;
    *S2 = 0;
    struct el* copia = primo;
    int appartiene = 0;

    // la lista è vuota
    if (primo == NULL) return;

    // se l'elemento centrale non esiste
    if (centrale == NULL) return;

    // controllo se centrale appartiene alla lista
    while (copia != NULL) {
        if (copia == centrale) {
            appartiene = 1;
        }

        copia = copia->next;
    }

    // l'elemento centrale non appartiene alla lista primo
    if (appartiene == 0) return; // o !appartiene

    // sommiamo i valori della prima metà
    while (primo != centrale) {
        *S1 = *S1 + primo->v;
        // *S1 += primo->v;

        primo = primo->next;
    }

    // sommiamo l'altra metà
    centrale = centrale->next;
    while (centrale != NULL) { // o != ULTIMO
        *S2 = *S2 + centrale->v;

        centrale = centrale->next;
    }
}
