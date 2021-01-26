#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  float val;
  struct node* next;
} ElemLista;

typedef ElemLista* Lista;

void Fondi(Lista L1, Lista L2, Lista* pL);
void insert(Lista* l, float val);
void stampa(Lista l);

int main() {
  Lista L1 = NULL;
  Lista L2 = NULL;
  Lista pl;

  insert(&L1, 2.0);
  insert(&L1, 4.3);
  insert(&L1, 5.0);
  insert(&L1, 7.5);
  insert(&L1, 10.0);

  insert(&L2, 1.0);
  insert(&L2, 3.14);
  insert(&L2, 11.1);

  Fondi(L1, L2, &pl);

  stampa(pl);

  return 0;
}

void Fondi(Lista L1, Lista L2, Lista* pL) {
  if (L1 != NULL && L2 != NULL) {
    if (L1->val < L2->val) {
      insert(pL, L1->val);

      Fondi(L1->next, L2, pL);
    } else {
      insert(pL, L2->val);

      Fondi(L1, L2->next, pL);
    }
  } else if (L2 != NULL) {
    insert(pL, L2->val);

    Fondi(L1, L2->next, pL);
  } else if (L1 != NULL) {
    insert(pL, L1->val);

    Fondi(L1->next, L2, pL);
  }
}

void insert(Lista* l, float val) {
  Lista cursore;

  if (*l == NULL) {
    *l = malloc(sizeof(ElemLista));

    (*l)->val = val;
    (*l)->next = NULL;

    return;
  }

  cursore = *l;
  while (cursore->next != NULL) cursore = cursore->next;

  if (cursore->val != val) {  // non tiene i duplicati in questo modo
    cursore->next = malloc(sizeof(ElemLista));

    cursore->next->val = val;
    cursore->next->next = NULL;
  }
}

void stampa(Lista l) {
  while (l != NULL) {
    printf("%f ", l->val);

    l = l->next;
  }
}