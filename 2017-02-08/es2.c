#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _p {
    int x, y;
    struct _p * next;
} punto_t;

int Scorciatoia(punto_t* A, punto_t* B);
float lunghezza(punto_t* list);

int main() {
    return 0;
}

int Scorciatoia(punto_t* A, punto_t* B) {
    punto_t* fineA, *fineB;
    float lungA, lungB;

    // se hanno lo stesso inizio
    if (A->x != B->x || A->y != B->y) {
        return 0;
    }

    // se hanno la stessa fine
    fineA = A;
    fineB = B;

    while (fineA->next != NULL) {
        fineA = fineA->next;
    }

    while (fineB->next != NULL) {
        fineB = fineB->next;
    }

    if (fineA->x != fineB->x || fineA->y != fineB->y) {
        return 0;
    }

    // se lung(A) < lung(B)
    lungA = lunghezza(A);
    lungB = lunghezza(B);

    if (lungA < lungB) {
        return 1;
    } else {
        return 0;
    }
}

float lunghezza(punto_t* list) {
    float lung = 0.0;

    // (1, 1), (2, 2), (3, 3)
    while (list->next != NULL) {
        lung += sqrt((list->x - list->next->x)*(list->x - list->next->x) + (list->y - list->next->y)*(list->y - list->next->y));

        list = list->next;
    }

    return lung;
}
