#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct node {
  int val;
  struct node* next;
} Node;

typedef Node* List;

void insertTail(List* l, int val);
List rlc(int arr[], int len);

int main() {
  int array[MAX] = {1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0,
                    0, 0, 0, 0, 1, 1, 1, 1, 1, 0};
  List l;
  List curs;

  l = rlc(array, 21);
  curs = l;

  while (curs != NULL) {
    printf("%d ", curs->val);

    curs = curs->next;
  }
  printf("\n");

  return 0;
}

void insertTail(List* l, int val) {
  Node* node = malloc(sizeof(Node));
  List curs;

  node->val = val;
  node->next = NULL;

  if (*l == NULL) {
    *l = node;
  } else {
    curs = *l;

    while (curs->next != NULL) {
      curs = curs->next;
    }

    curs->next = node;
  }
}

List rlc(int arr[], int len) {
  int curr = 0;
  int cont = 0;
  int i;
  List l = NULL;

  for (i = 0; i < len; i++) {
    if (arr[i] != curr) {
      insertTail(&l, cont);

      cont = 1;
      curr = !curr;
    } else {
      cont++;
    }
  }

  insertTail(&l, cont);

  return l;
}