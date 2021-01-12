#include <stdio.h>

#define MAX 19

struct counter {
    char carattere;
    int occorrenze;
};

struct lista {
    struct counter valori[MAX];
    int numeroValori;
};

typedef struct lista ListaOccorrenze;
typedef char Parola[MAX + 1];

void costruisciLista(Parola parola, ListaOccorrenze* lista);

int main() {
    ListaOccorrenze lista;
    Parola parola = "amaca";
    int i;

    lista.numeroValori = 0;

    costruisciLista(parola, &lista);

    for (i = 0; i < lista.numeroValori; i++) {
        printf("Carattere: %c\n", lista.valori[i].carattere);
        printf("Occorrenze: %d\n", lista.valori[i].occorrenze);
    }

    return 0;
}

void costruisciLista(Parola parola, ListaOccorrenze* lista) {
    int i;
    int trovato = 0;

    if (*parola == '\0') {
        return;
    }

    for (i = 0; i < lista->numeroValori && !trovato; i++) {
        if (lista->valori[i].carattere == *parola) {
            trovato = 1;
            lista->valori[i].occorrenze++;
        }
    }

    if (!trovato) {
        lista->valori[lista->numeroValori].carattere = *parola;
        lista->valori[lista->numeroValori].occorrenze = 1;

        lista->numeroValori++;
    }

    costruisciLista(parola + 1, lista);
}
