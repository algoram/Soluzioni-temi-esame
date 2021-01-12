#include <stdio.h>

#define MAX 4

void massimiLocali(int matrice[][MAX]);

int main() {
    int matrice[MAX][MAX] = {12, 11, 14, 15, 8, 15, 9, 17, 13, 10, 11, 10, 7, 6, 12, 11};
    int i, j;

    massimiLocali(matrice);

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%2d ", matrice[i][j]);
        }

        printf("\n");
    }

    return 0;
}

void massimiLocali(int matrice[][MAX]) {
    int copia[MAX][MAX];
    int i, j, k, l;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            copia[i][j] = matrice[i][j];
        }
    }

    // scorro ogni cella della matrice
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            // per ogni cella della matrice controllo i vicini
            for (k = -1; k < 2; k++) {
                for (l = -1; l < 2; l++) {
                    // ignoro l'elemento centrale
                    if (k != 0 || l != 0) {
                        // effettuo i controlli
                        if (i + k >= 0 && i + k < MAX && j + l >= 0 && j + l < MAX) {
                            // se è maggiore
                            if (copia[i][j] > copia[i+k][j+l]) {
                                matrice[i+k][j+l] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
}
