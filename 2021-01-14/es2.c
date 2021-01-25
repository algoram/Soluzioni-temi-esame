#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int val;
  struct nodo* next;
} Nodo;

typedef Nodo* Lista;

Lista inversa(Lista l, Lista* Linv);
Lista insert(Lista l, int val);
void stampa(Lista l);

int main() {
  Lista l1 = NULL;
  Lista l2;

  l1 = insert(l1, 3);
  l1 = insert(l1, 2);
  l1 = insert(l1, 1);

  inversa(l1, &l2);

  stampa(l1);
  stampa(l2);

  return 0;
}

Lista inversa(Lista l, Lista* Linv) {
  Nodo* nuovo;
  Nodo* prec;

  nuovo = malloc(sizeof(Nodo));

  nuovo->next = NULL;
  nuovo->val = l->val;

  if (l->next == NULL) {
    *Linv = nuovo;
  } else {
    prec = inversa(l->next, Linv);

    prec->next = nuovo;
  }

  return nuovo;
}

Lista insert(Lista l, int val) {
  Nodo* nuovo = malloc(sizeof(Nodo));

  nuovo->val = val;
  nuovo->next = l;

  return nuovo;
}

void stampa(Lista l) {
  while (l != NULL) {
    printf("%d ", l->val);

    l = l->next;
  }

  printf("\n");
}