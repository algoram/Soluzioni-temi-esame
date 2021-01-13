#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo* prossimo;
} Nodo;

typedef struct nodo2 {
    int valore;
    int occorrenze;
    struct nodo2* prossimo;
} Nodo2;

Nodo2* insert(Nodo2* lista, int valore);
Nodo* elimina(Nodo* lista, int n);
Nodo* cancella(Nodo* lista);

int main() {


    return 0;
}

/*
lista: [1, 2, 3, 1, 2, 3, 1, 2]
n: 3

lista2: [(1, 3), (2, 3), (3, 2)]

output: [3, 3]
*/
Nodo* elimina(Nodo* lista, int n) {
    Nodo2* lista2 = NULL;
    Nodo* cursore = lista;
    Nodo2* cursore2;

    while (cursore != NULL) {
        lista2 = insert(lista2, cursore->valore);

        cursore = cursore->prossimo;
    }

    // eliminiamo quelli che compaiono >= n volte
    cursore2 = lista2;

    while (cursore2 != NULL) {
        if (cursore2->occorrenze >= n) {
            if (lista->valore == cursore2->valore) {
                lista = cancella(lista);
            }

            cursore = lista;

            while (cursore->prossimo != NULL) {
                if (cursore->prossimo->valore == cursore2->valore) {
                    cursore->prossimo = cancella(cursore->prossimo);
                }

                cursore = cursore->prossimo;
            }
        }

        cursore2 = cursore2->prossimo;
    }

    return lista;
}

Nodo2* insert(Nodo2* lista, int valore) {
    Nodo2* cursore;
    int trovato;

    if (lista == NULL) {
        Nodo2* nuovo = malloc(sizeof(Nodo2));

        nuovo->valore = valore;
        nuovo->occorrenze = 1;
        nuovo->prossimo = NULL;

        return nuovo;
    } else {
        cursore = lista;
        trovato = 0;

        if (cursore->valore == valore) {
            cursore->occorrenze++;
        } else {
            while (cursore->prossimo != NULL && trovato == 0) {
                if (cursore->prossimo->valore == valore) {
                    trovato = 1;
                }
            }

            if (trovato) {
                cursore->prossimo->occorrenze++;
            } else {
                cursore->prossimo = malloc(sizeof(Nodo2));

                cursore->prossimo->valore = valore;
                cursore->prossimo->occorrenze = 1;
                cursore->prossimo->prossimo = NULL;
            }
        }
    }

    return lista;
}

Nodo* cancella(Nodo* lista) {
    Nodo* riferimento = lista;

    lista = lista->prossimo;

    free(riferimento);

    return lista;
}
