#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct node {
  int val;
  struct node* next;
} Node;

typedef Node* List;

void moltiplica(int array[], List* list);
void insert(List* list, int val);
void elimina(List* list, int val);

int main() {
  int array[MAX] = {1, 2, 3, 4, 5};
  List l;
  List cursor;

  moltiplica(array, &l);

  cursor = l;
  while (cursor != NULL) {
    printf("%d ", cursor->val);

    cursor = cursor->next;
  }
  printf("\n");

  elimina(&l, 15);

  cursor = l;
  while (cursor != NULL) {
    printf("%d ", cursor->val);

    cursor = cursor->next;
  }
  printf("\n");

  return 0;
}

void moltiplica(int array[], List* list) {
  int i;
  *list = NULL;  // svuotiamo la lista

  for (i = 0; i < MAX; i++) {
    insert(list, array[i] * 5);
  }
}

void insert(List* list, int val) {
  List node = malloc(sizeof(Node));
  List cursor;

  node->val = val;
  node->next = NULL;

  if (*list == NULL) {
    *list = node;
  } else {
    cursor = *list;

    while (cursor->next != NULL) {
      cursor = cursor->next;
    }

    cursor->next = node;
  }
}

void elimina(List* list, int val) {
  List rif;
  List cursor;

  if ((*list)->val == val) {
    rif = *list;

    *list = (*list)->next;

    free(rif);
  } else {
    cursor = *list;

    while (cursor->next->val != val) {
      cursor = cursor->next;
    }

    rif = cursor->next;

    cursor->next = cursor->next->next;

    free(rif);
  }
}