#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef Node* List;

void printList(List l);
List insert(List l, int val, int k);

int main() {
    List list = NULL;

    list = insert(list, 7, 1);
    list = insert(list, 6, 1);
    list = insert(list, 5, 1);
    list = insert(list, 4, 1);
    list = insert(list, 2, 1);
    list = insert(list, 1, 1);

    printList(list);

    list = insert(list, 3, 3);

    printList(list);

    return 0;
}

void printList(List l) {
    if (l == NULL) {
        printf("\n");
        return;
    }

    printf("%d ", l->value);

    printList(l->next);
}

List insert(List l, int val, int k) {
    int numElem = 0;
    int i;
    List cursor = l;
    Node* newNode;

    // creo l'elemento
    newNode = malloc(sizeof(Node));
    newNode->value = val;

    // conto gli elementi
    while (cursor != NULL) {
        numElem++;
        cursor = cursor->next;
    }

    // inserimento in testa
    if (k > numElem) {
        newNode->next = l;

        return newNode;
    }

    // inserimento in mezzo
    cursor = l;
    for (i = 0; i < numElem - k; i++) {
        cursor = cursor->next;
    }

    newNode->next = cursor->next;
    cursor->next = newNode;

    return l;
}
