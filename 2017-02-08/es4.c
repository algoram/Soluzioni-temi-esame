#include <stdio.h>

#define N 3

/*

[1, 2, 3]
[2, 1, 3]
[3, 2, 1]

dim: 1

=> simmetrica? SI

*/

typedef enum {false, true} Bool;

Bool simmetrica(int matrice[][N], int dimensione);

int main() {
    int matrice[N][N] = {{1, 2, 3}, {2, 1, 3}, {3, 3, 1}};
    Bool simm = simmetrica(matrice, N);

    if (simm) {
        printf("La matrice e' simmetrica\n");
    } else {
        printf("La matrice non e' simmetrica\n");
    }

    return 0;
}

Bool simmetrica(int matrice[][N], int dimensione) {
    int i;

    if (dimensione == 1) {
        return true;
    }

    for (i = 0; i < dimensione; i++) {
        if (matrice[i][dimensione-1] != matrice[dimensione-1][i]) {
            return false;
        }
    }

    return simmetrica(matrice, dimensione-1);
}
