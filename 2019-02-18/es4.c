#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node* next;
} Node;

typedef Node* List;

List inserisciSeNuovo(List l, int val);
List insert(List l, int val);
float mediaValoriDiversi(List list);

int main() {
  List l = NULL;

  l = insert(l, 8);
  l = insert(l, 3);
  l = insert(l, 4);
  l = insert(l, 3);
  l = insert(l, 7);

  printf("La media dei valori diversi e': %f\n", mediaValoriDiversi(l));

  return 0;
}

List inserisciSeNuovo(List l, int val) {
  List cursore;

  if (l == NULL) {
    l = malloc(sizeof(Node));

    l->val = val;
    l->next = NULL;

    return l;
  }

  cursore = l;
  while (cursore->next != NULL) {
    if (cursore->val == val) {
      return l;
    }

    cursore = cursore->next;
  }

  cursore->next = malloc(sizeof(Node));

  cursore->next->val = val;
  cursore->next->next = NULL;

  return l;
}

List insert(List l, int val) {
  Node* node = malloc(sizeof(Node));

  node->next = l;
  node->val = val;

  return node;
}

float mediaValoriDiversi(List list) {
  float totale;
  int numero;
  List nuova = NULL, cursore;

  while (list != NULL) {
    nuova = inserisciSeNuovo(nuova, list->val);

    list = list->next;
  }

  numero = 0;
  totale = 0.0;
  cursore = nuova;
  while (cursore != NULL) {
    numero++;
    totale += cursore->val;

    cursore = cursore->next;
  }

  return totale / numero;
}