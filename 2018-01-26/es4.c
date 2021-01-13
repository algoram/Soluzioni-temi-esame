#include <stdio.h>
#include <stdlib.h>

typedef struct node1 {
  int val;
  struct node1* next;
} Node1;

typedef struct node2 {
  int val;
  struct node2* next;
  struct node2* prev;
} Node2;

typedef Node1* List1;
typedef Node2* List2;

void insert(List1* l, int val);
List2 converti(List1 l);
void stampaLista(List2 l);

int main() {
  List1 l1 = NULL;
  List2 l2;

  insert(&l1, 3);
  insert(&l1, 2);
  insert(&l1, 1);

  l2 = converti(l1);

  stampaLista(l2);

  return 0;
}

void insert(List1* l, int val) {
  Node1* node = malloc(sizeof(Node1));

  node->val = val;
  node->next = *l;
  *l = node;
}

List2 converti(List1 l) {
  Node2* newNode;
  List2 newList;

  if (l == NULL) {
    return NULL;
  }

  newNode = malloc(sizeof(Node2));
  newList = converti(l->next);

  newNode->val = l->val;
  newNode->next = newList;
  newNode->prev = NULL;

  if (newList != NULL) {
    newList->prev = newNode;
  }

  return newNode;
}

void stampaLista(List2 l) {
  printf("Dritto: ");
  while (l->next != NULL) {
    printf("%d ", l->val);

    l = l->next;
  }
  printf("%d ", l->val);
  printf("\n");

  printf("Al contrario: ");
  while (l->prev != NULL) {
    printf("%d ", l->val);

    l = l->prev;
  }
  printf("%d ", l->val);
  printf("\n");
}