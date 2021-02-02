#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node* next;
} Node;

typedef Node* List;

void insert(List* l, int val);
void Scambia(List* l);
void stampa(List l);

int main() {
  List l = NULL;

  insert(&l, 8);
  insert(&l, 7);
  insert(&l, 6);
  insert(&l, 5);
  insert(&l, 4);
  insert(&l, 3);

  stampa(l);

  Scambia(&l);

  stampa(l);

  return 0;
}

void insert(List* l, int val) {
  Node* node = malloc(sizeof(Node));

  node->val = val;
  node->next = *l;

  *l = node;
}

/*
[3, 4, 5, 6, 7, 8]

[4, 3, 6, 5, 8, 7]
*/
void Scambia(List* l) {
  Node* temp;

  if (*l == NULL) return;

  temp = *l;
  *l = temp->next;
  temp->next = (*l)->next;
  (*l)->next = temp;

  Scambia(&((*l)->next->next));
}

void stampa(List l) {
  while (l != NULL) {
    printf("%d ", l->val);

    l = l->next;
  }
  printf("\n");
}