#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    float peso;
    float volume;
    struct node* nextPeso;
    struct node* nextVolume;
} Node;

typedef struct list {
    Node* firstPeso;
    Node* firstVolume;
} List;

void inserisci(List* l, float peso, float volume); // funzione per provare
void stampaLista(List l); // funzione per provare
void cancellaMinorPS(List* l);

int main() {
    List l;
    l.firstPeso = NULL;
    l.firstVolume = NULL;

    inserisci(&l, 1, 3);
    inserisci(&l, 2, 2);
    inserisci(&l, 3, 1);

    stampaLista(l);

    cancellaMinorPS(&l);

    stampaLista(l);

    return 0;
}

void inserisci(List* l, float peso, float volume) {
    Node* newNode = malloc(sizeof(Node));
    Node* cursore;
    int primo, secondo;

    newNode->peso = peso;
    newNode->volume = volume;
    newNode->nextPeso = NULL;
    newNode->nextVolume = NULL;

    if (l->firstPeso == NULL && l->firstVolume == NULL) {
        // lista vuota, primo elemento
        l->firstPeso = newNode;
        l->firstVolume = newNode;
    } else {
        primo = 0;
        secondo = 0;

        // inserimento ordinato nella prima lista
        if (peso < l->firstPeso->peso) {
            newNode->nextPeso = l->firstPeso;
            l->firstPeso = newNode;
            primo = 1;
        }

        cursore = l->firstPeso;
        while (cursore != NULL && !primo) {
            if (cursore->nextPeso == NULL || peso < cursore->nextPeso->peso) {
                newNode->nextPeso = cursore->nextPeso;
                cursore->nextPeso = newNode;
                primo = 1;
            }

            cursore = cursore->nextPeso;
        }

        // inserimento ordinato nella seconda lista
        if (volume < l->firstVolume->volume) {
            newNode->nextVolume = l->firstVolume;
            l->firstVolume = newNode;
            secondo = 1;
        }

        cursore = l->firstVolume;
        while (cursore != NULL && !secondo) {
            if (cursore->nextVolume == NULL || volume < cursore->nextVolume->volume) {
                newNode->nextVolume = cursore->nextVolume;
                cursore->nextVolume = newNode;
                secondo = 1;
            }

            cursore = cursore->nextVolume;
        }
    }
}

void stampaLista(List l) {
    printf("Ordinata per peso: ");
    while (l.firstPeso != NULL) {
        printf("[%f, %f] ", l.firstPeso->peso, l.firstPeso->volume);

        l.firstPeso = l.firstPeso->nextPeso;
    }

    printf("\n");
    printf("Ordinata per volume: ");
    while (l.firstVolume != NULL) {
        printf("[%f, %f] ", l.firstVolume->peso, l.firstVolume->volume);

        l.firstVolume = l.firstVolume->nextVolume;
    }

    printf("\n");
}

void cancellaMinorPS(List* l) {
    Node* daCancellare;
    Node* cursore;
    float minimo, ps;

    if (l->firstPeso == NULL) {
        return;
    }

    // cerco l'elemento col minor peso specifico scorrendo solo una lista
    minimo = l->firstPeso->peso / l->firstPeso->volume;
    daCancellare = l->firstPeso;

    cursore = l->firstPeso->nextPeso;

    while (cursore != NULL) {
        ps = cursore->peso / cursore->volume;

        if (ps < minimo) {
            minimo = ps;
            daCancellare = cursore;
        }

        cursore = cursore->nextPeso;
    }

    // cancello l'elemento nella prima lista
    if (l->firstPeso == daCancellare) {
        l->firstPeso = l->firstPeso->nextPeso;
    }

    cursore = l->firstPeso;

    while (cursore->nextPeso != NULL && cursore->nextPeso != daCancellare) {
        cursore = cursore->nextPeso;
    }

    if (cursore->nextPeso != NULL) {
        cursore->nextPeso = cursore->nextPeso->nextPeso;
    }

    // cancello l'elemento nella seconda lista
    if (l->firstVolume == daCancellare) {
        l->firstVolume = l->firstVolume->nextVolume;
    }

    cursore = l->firstVolume;

    while (cursore->nextVolume != NULL && cursore->nextVolume != daCancellare) {
        cursore = cursore->nextVolume;
    }

    if (cursore->nextVolume != NULL) {
        cursore->nextVolume = cursore->nextVolume->nextVolume;
    }

    // libero la memoria
    free(daCancellare);
}
