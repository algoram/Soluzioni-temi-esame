#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int numero;
    int occorrenze;
    struct node* next;
} Node;

typedef Node* List;

List cercaInteri(FILE* file);
List inserimento(List list, int numero);

int main() {
    FILE* file = NULL;
    List list = NULL, cursor;

    file = fopen("es1.txt", "r");

    list = cercaInteri(file);

    cursor = list;
    while (cursor != NULL) {
        printf("(%d, %d)\n", cursor->numero, cursor->occorrenze);
        cursor = cursor->next;
    }

    fclose(file);

    return 0;
}

List cercaInteri(FILE* file) {
    List list = NULL;
    int numero;

    while (fscanf(file, "%d", &numero) != EOF) {
        list = inserimento(list, numero);
    }

    return list;
}

List inserimento(List list, int numero) {
    List cursor;

    // 1) lista vuota
    if (list == NULL) {
        list = malloc(sizeof(Node));

        list->numero = numero;
        list->occorrenze = 1;
        list->next = NULL;
    } else {
        cursor = list;

        if (list->numero == numero) {
            list->occorrenze++;
        } else {
            while (cursor->next != NULL && cursor->next->numero != numero) {
                cursor = cursor->next;
            }

            if (cursor->next != NULL) { // 2) lista che ha già il valore all'interno
                cursor->next->occorrenze++;
            } else {    // 3) lista che non ha il valore all'interno
                cursor->next = malloc(sizeof(Node));

                cursor->next->numero = numero;
                cursor->next->occorrenze = 1;
                cursor->next->next = NULL;
            }
        }
    }

    return list;
}
