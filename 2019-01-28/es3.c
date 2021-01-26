#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node* next;
} Node;

typedef Node* List;

List elementiPari(List l);
List insert(List l, int val);
void printList(List l);

int main() {
  List l1 = NULL;
  List l2;

  l1 = insert(l1, 1);
  l1 = insert(l1, 2);
  l1 = insert(l1, 3);
  l1 = insert(l1, 4);
  l1 = insert(l1, 5);

  l2 = elementiPari(l1);

  printList(l2);

  return 0;
}

List elementiPari(List l) {
  List nuova = NULL;

  while (l != NULL) {
    l = l->next;

    if (l != NULL) {
      nuova = insert(nuova, l->val);

      l = l->next;
    }
  }

  return nuova;
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
  while (cursor->next != NULL) cursor = cursor->next;

  cursor->next = malloc(sizeof(Node));

  cursor->next->next = NULL;
  cursor->next->val = val;

  return l;
}

void printList(List l) {
  while (l != NULL) {
    printf("%d ", l->val);

    l = l->next;
  }
}