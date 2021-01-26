#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  float val;
  struct node* next;
} Node;

typedef Node* List;

void BubbleSort(List l);
List insert(List l, float val);
void printList(List l);

int main() {
  List l = NULL;

  l = insert(l, 4.0);
  l = insert(l, 1.0);
  l = insert(l, 2.0);
  l = insert(l, 3.0);

  BubbleSort(l);

  printList(l);

  return 0;
}

void BubbleSort(List l) {
  List cursor;
  float temp;
  int finished = 0;

  while (!finished) {
    finished = 1;
    cursor = l;

    while (cursor->next != NULL) {
      if (cursor->val > cursor->next->val) {
        temp = cursor->val;
        cursor->val = cursor->next->val;
        cursor->next->val = temp;

        finished = 0;
      }

      cursor = cursor->next;
    }
  }
}

List insert(List l, float val) {
  Node* newNode = malloc(sizeof(Node));

  newNode->val = val;
  newNode->next = l;

  return newNode;
}

void printList(List l) {
  while (l != NULL) {
    printf("%f ", l->val);

    l = l->next;
  }
}