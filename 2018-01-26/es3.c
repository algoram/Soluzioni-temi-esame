#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char val;
  struct node* next;
} Node;

typedef Node* List;

void insert(List* l, char v);
void cancellaCentro(List* l);
void stampaLista(List list);

int main() {
  List l = NULL;

  insert(&l, 'a');
  insert(&l, 'b');
  insert(&l, 'c');
  insert(&l, 'd');
  insert(&l, 'e');

  stampaLista(l);

  cancellaCentro(&l);

  stampaLista(l);

  return 0;
}

void insert(List* l, char v) {
  Node* node = malloc(sizeof(Node));

  node->val = v;

  node->next = *l;
  *l = node;
}

void cancellaCentro(List* l) {
  List curs1, curs2, temp;

  if ((*l)->next == NULL) {
    temp = *l;

    *l = NULL;

    free(temp);
  } else {
    curs1 = *l;
    curs2 = (*l)->next;

    while (curs2->next != NULL) {
      curs2 = curs2->next;

      if (curs2->next != NULL) {
        curs2 = curs2->next;
      }

      if (curs2->next != NULL) {
        curs1 = curs1->next;
      }
    }

    temp = curs1->next;

    curs1->next = temp->next;

    free(temp);
  }
}

void stampaLista(List list) {
  while (list != NULL) {
    printf("%c", list->val);

    list = list->next;
  }
  printf("\n");
}