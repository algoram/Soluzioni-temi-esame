#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node* next;
} Node;

typedef Node* List;

List centroLista(List l);
List insert(List l, int val);

int main() {
  List l = NULL;
  List centro;

  l = insert(l, 3);
  l = insert(l, 2);
  l = insert(l, 1);

  centro = centroLista(l);

  printf("%d\n", centro->val);

  return 0;
}

List centroLista(List l) {
  List cursore1, cursore2;

  cursore1 = l;
  cursore2 = l;

  while (cursore2->next != NULL) {
    cursore2 = cursore2->next;

    if (cursore2->next != NULL) {
      cursore1 = cursore1->next;
      cursore2 = cursore2->next;
    }
  }

  return cursore1;
}

List insert(List l, int val) {
  Node* node = malloc(sizeof(Node));

  node->val = val;
  node->next = l;

  return node;
}
