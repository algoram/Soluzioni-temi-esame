#include <stdio.h>
#include <stdlib.h>

typedef enum {oper, val} Tipo;

typedef struct El {
    Tipo tipo;
    char operatore;
    float valore;
    struct El *next;
} Elemento;

float Calcola(Elemento *Punt) {
    Elemento *PrimoOperando, *SecondoOperando;
    Elemento *Cursore;
    int stato = 1;

    if (Punt->tipo == val) return (Punt->valore); /* caso base, non ricorsivo */

    PrimoOperando = Punt->next; /* localizza il primo operando */

    /* localizza il secondo operando */
    Cursore = Punt;

    while (Cursore->next != NULL && stato != 0) {

        if (Cursore->next->tipo == val) stato--;
        else stato++;

        Cursore = Cursore->next;
    }

    SecondoOperando = Cursore->next;

    if (Punt->operatore == '+') return (Calcola(PrimoOperando) + Calcola(SecondoOperando));
    if (Punt->operatore == '-') return (Calcola(PrimoOperando) - Calcola(SecondoOperando));
    if (Punt->operatore == '*') return (Calcola(PrimoOperando) * Calcola(SecondoOperando));
    if (Punt->operatore == '/') return (Calcola(PrimoOperando) / Calcola(SecondoOperando));
}

Elemento* insert(Elemento* elem, Tipo tipo, char operatore, float valore) {
    Elemento* nuovo = malloc(sizeof(Elemento));

    nuovo->tipo = tipo;
    nuovo->operatore = operatore;
    nuovo->valore = valore;

    nuovo->next = elem;

    return nuovo;
}

int main() {
    Elemento* operazione = NULL;
    float risultato;

    operazione = insert(operazione, val, '+', 7.0);
    operazione = insert(operazione, val, '+', 0.5);
    operazione = insert(operazione, val, '+', 1.5);
    operazione = insert(operazione, oper, '+', 0.0);
    operazione = insert(operazione, val, '+', 5.0);
    operazione = insert(operazione, oper, '-', 0.0);
    operazione = insert(operazione, oper, '*', 0.0);

    risultato = Calcola(operazione);

    printf("Il risultato dell'operazione e' %f\n", risultato);

    return 0;
}
