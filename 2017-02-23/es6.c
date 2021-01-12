#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct nodo {
    char carattere;
    int occorrenze;
    struct nodo* next;
} Nodo;

typedef char Parola[MAX];
typedef Nodo* ListaDinamicaOccorrenze;

ListaDinamicaOccorrenze costruisciLista(Parola parola);
ListaDinamicaOccorrenze inserisci(ListaDinamicaOccorrenze lista, char c);

int main() {
    ListaDinamicaOccorrenze lista, cursore;
    Parola parola = "amaca";

    lista = costruisciLista(parola);
    cursore = lista;

    while (cursore != NULL) {
        printf("(%c, %d)\n", cursore->carattere, cursore->occorrenze);

        cursore = cursore->next;
    }

    return 0;
}

ListaDinamicaOccorrenze costruisciLista(Parola parola) {
    ListaDinamicaOccorrenze lista = NULL;
    ListaDinamicaOccorrenze cursore;
    int trovato;

    while (*parola != '\0') {
        cursore = lista;
        trovato = 0;

        // controllo se c'è già il carattere
        while (cursore != NULL) {
            if (cursore->carattere == *parola) {
                cursore->occorrenze++;
                trovato = 1;
            }

            cursore = cursore->next;
        }

        if (!trovato) {
            lista = inserisci(lista, *parola);
        }

        parola++;
    }

    return lista;
}

ListaDinamicaOccorrenze inserisci(ListaDinamicaOccorrenze lista, char c) {
    Nodo* nuovo = malloc(sizeof(Nodo));
    Nodo* cursore;

    nuovo->carattere = c;
    nuovo->occorrenze = 1;
    nuovo->next = NULL;

    // se la lista è vuota ritorniamo l'elemento
    if (lista == NULL) {
        return nuovo;
    }

    // se è minore del primo carattere inseriamo in testa
    if (c < lista->carattere) {
        nuovo->next = lista;

        return nuovo;
    }

    // altrimenti inseriamo nella giusta posizione
    cursore = lista;
    while (cursore->next != NULL) {
        if (c < cursore->next->carattere) {
            nuovo->next = cursore->next;
            cursore->next = nuovo;

            return lista;
        }

        cursore = cursore->next;
    }

    // se arrivo qui devo inserire in coda
    cursore->next = nuovo;

    return lista;
}
