#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node* next;
} Node;

typedef Node* List;

List fusione(List l1, List l2);
List insert(List l, int val);
void stampa(List l);

int main() {
  List l1 = NULL;
  List l2 = NULL;
  List l3;

  l1 = insert(l1, 2);
  l1 = insert(l1, 4);
  l1 = insert(l1, 5);
  l1 = insert(l1, 7);
  l1 = insert(l1, 9);
  l1 = insert(l1, 10);

  l2 = insert(l2, 1);
  l2 = insert(l2, 3);
  l2 = insert(l2, 11);

  l3 = fusione(l1, l2);

  stampa(l3);

  return 0;
}

List fusione(List l1, List l2) {
  List l3 = NULL;

  while (l1 != NULL && l2 != NULL) {
    if (l1->val < l2->val) {
      l3 = insert(l3, l1->val);

      l1 = l1->next;
    } else {
      l3 = insert(l3, l2->val);

      l2 = l2->next;
    }
  }

  while (l1 != NULL) {
    l3 = insert(l3, l1->val);

    l1 = l1->next;
  }

  while (l2 != NULL) {
    l3 = insert(l3, l2->val);

    l2 = l2->next;
  }

  return l3;
}

List insert(List l, int val) {
  List cursor;

  if (l == NULL) {
    l = malloc(sizeof(Node));

    l->val = val;
    l->next = NULL;

    return l;
  }

  cursor = l;
  while (cursor->next != NULL) {
    cursor = cursor->next;
  }

  cursor->next = malloc(sizeof(Node));

  cursor->next->val = val;
  cursor->next->next = NULL;

  return l;
}

void stampa(List l) {
  while (l != NULL) {
    printf("%d ", l->val);

    l = l->next;
  }
  printf("\n");
}