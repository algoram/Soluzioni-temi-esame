#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node* next;
} Node;

typedef Node* List;

List rlc(int array[], int lung);

int main() {
  int array[] = {0, 0, 0, 1, 1, 0, 0, 1, 1, 0};
  int lung = 10;
  List lista, cursore;

  lista = rlc(array, lung);

  cursore = lista;
  while (cursore != NULL) {
    printf("%d ", cursore->val);

    cursore = cursore->next;
  }

  return 0;
}

List rlc(int array[], int lung) {
  List testa, cursore;
  int i;
  int num;

  testa = malloc(sizeof(Node));
  testa->val = 0;
  testa->next = NULL;

  cursore = testa;

  num = 0;
  for (i = 0; i < lung; i++) {
    if (array[i] == num) {
      cursore->val++;
    } else {
      cursore->next = malloc(sizeof(Node));

      cursore = cursore->next;
      cursore->val = 1;
      cursore->next = NULL;

      num = !num;
    }
  }

  return testa;
}