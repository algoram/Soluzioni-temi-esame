#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node* next;
} Node;

typedef struct nodecont {
  int val;
  int occ;
  struct nodecont* next;
} NodeCont;

typedef Node* List;
typedef NodeCont* ListCont;

List cancellaK(List l, int k);
ListCont insert(ListCont l, int val);
List inserisciTesta(List l, int val);
List cancellaTutti(List l, int val);
int cancellaVal(List* l, int val);
void stampa(List l);
void stampaOcc(ListCont l);

int main() {
  List l = NULL;

  l = inserisciTesta(l, 7);
  l = inserisciTesta(l, 5);
  l = inserisciTesta(l, 4);
  l = inserisciTesta(l, 7);
  l = inserisciTesta(l, 4);
  l = inserisciTesta(l, 5);
  l = inserisciTesta(l, 7);

  stampa(l);

  l = cancellaK(l, 3);

  stampa(l);

  return 0;
}

List cancellaK(List l, int k) {
  ListCont occ, curs2;
  List curs;

  // costruisco la lista delle occorrenze
  occ = NULL;
  curs = l;
  while (curs != NULL) {
    occ = insert(occ, curs->val);

    curs = curs->next;
  }

  stampaOcc(occ);

  // cancello tutti quelli che hanno occorrenza >= k
  curs2 = occ;
  while (curs2 != NULL) {
    if (curs2->occ >= k) {
      l = cancellaTutti(l, curs2->val);
    }

    curs2 = curs2->next;
  }

  return l;
}

ListCont insert(ListCont l, int val) {
  ListCont curs;

  if (l == NULL) {
    l = malloc(sizeof(NodeCont));

    l->val = val;
    l->occ = 1;
    l->next = NULL;

    return l;
  }

  if (l->val == val) {
    l->occ++;

    return l;
  }

  curs = l;
  while (curs->next != NULL) {
    if (curs->next->val == val) {
      curs->next->occ++;

      return l;
    }

    curs = curs->next;
  }

  curs->next = malloc(sizeof(NodeCont));
  curs = curs->next;
  curs->val = val;
  curs->occ = 1;
  curs->next = NULL;

  return l;
}

List inserisciTesta(List l, int val) {
  Node* temp = malloc(sizeof(Node));

  temp->val = val;
  temp->next = l;

  return temp;
}

List cancellaTutti(List l, int val) {
  int haCancellato;

  haCancellato = cancellaVal(&l, val);
  while (haCancellato) {
    haCancellato = cancellaVal(&l, val);
  }

  return l;
}

int cancellaVal(List* l, int val) {
  List temp, curs;

  // se e' il primo elemento
  if ((*l)->val == val) {
    temp = *l;
    *l = (*l)->next;
    free(temp);

    return 1;
  }

  // caso generale
  curs = *l;
  while (curs->next != NULL) {
    if (curs->next->val == val) {
      temp = curs->next;
      curs->next = curs->next->next;
      free(temp);

      return 1;
    }

    curs = curs->next;
  }

  return 0;
}

void stampa(List l) {
  printf("[%d", l->val);
  l = l->next;

  while (l != NULL) {
    printf(", %d", l->val);
    l = l->next;
  }

  printf("]\n");
}

void stampaOcc(ListCont l) {
  printf("[(%d,%d)", l->val, l->occ);
  l = l->next;

  while (l != NULL) {
    printf(", (%d,%d)", l->val, l->occ);
    l = l->next;
  }

  printf("]\n");
}