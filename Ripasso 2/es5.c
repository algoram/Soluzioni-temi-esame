#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* next;
  struct node* prec;
} Node;

typedef struct list {
  Node* first;
  Node* last;
} List;

void insert(List* l, int val);
void stampa(List l);

int main() {
  List l;
  l.first = NULL;
  l.last = NULL;

  insert(&l, 1);
  insert(&l, 2);
  insert(&l, 4);

  stampa(l);

  return 0;
}

void insert(List* l, int val) {
  Node* node = malloc(sizeof(Node));
  Node* cursor;
  int inserito;

  node->value = val;
  node->next = NULL;
  node->prec = NULL;

  if (l->first == NULL && l->last == NULL) {
    l->first = node;
    l->last = node;
  } else {
    // se è il primo
    if (val < l->first->value) {
      // settiamo i prec
      l->first->prec = node;
      node->prec = NULL;

      // settiamo i next
      node->next = l->first;
      l->first = node;
    } else {
      cursor = l->first;
      inserito = 0;

      while (cursor->next != NULL && !inserito) {
        if (val < cursor->next->value) {
          cursor->next->prec = node;
          node->prec = cursor;

          node->next = cursor->next;
          cursor->next = node;

          inserito = 1;
        }

        cursor = cursor->next;
      }

      if (!inserito) {
        node->prec = cursor;
        cursor->next = node;

        l->last = node;
      }
    }
  }
}

void stampa(List l) {
  printf("Dritto: ");
  while (l.first != NULL) {
    printf("%d ", l.first->value);

    l.first = l.first->next;
  }
  printf("\n");

  printf("Storto: ");
  while (l.last != NULL) {
    printf("%d ", l.last->value);

    l.last = l.last->prec;
  }
  printf("\n");
}