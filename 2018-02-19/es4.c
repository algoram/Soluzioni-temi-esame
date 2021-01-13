#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct node {
  char val;
  struct node* next;
} Node;

typedef Node* List;

int AlmenoN(List l, char c, int k);
int AlmenoNconsec(List l, char c, int k);
void insert(List* l, char c);

int main() {
  List l = NULL;

  insert(&l, 'a');
  insert(&l, 'a');
  insert(&l, 'b');
  insert(&l, 'a');

  if (AlmenoN(l, 'a', N)) {
    printf("Ci sono almeno %d '%c' nella lista\n", N, 'a');
  }

  if (AlmenoNconsec(l, 'a', N)) {
    printf("Ci sono almeno %d '%c' consecutive nella lista\n", N, 'a');
  }

  return 0;
}

int AlmenoN(List l, char c, int k) {
  if (k == 0) return 1;
  // messo dopo perché magari la lista è finita ma conteneva k caratteri
  if (l == NULL) return 0;

  if (l->val == c) {
    return AlmenoN(l->next, c, k - 1);
  }

  return AlmenoN(l->next, c, k);
}

int AlmenoNconsec(List l, char c, int k) {
  if (k == 0) return 1;
  if (l == NULL) return 0;

  if (l->val == c) {
    return AlmenoNconsec(l->next, c, k - 1);
  }

  // non sono convinto sia il modo giusto, ma il testo afferma che N è globale
  return AlmenoNconsec(l->next, c, N);
}

void insert(List* l, char c) {
  Node* node = malloc(sizeof(Node));

  node->val = c;
  node->next = *l;
  *l = node;
}