#include <stdio.h>

#define N 3

typedef int Matrice[N][N];

int diffDiagonali(Matrice mat, int indice, int dimensione);

int main() {
    Matrice matrice = {{2, 1, 4}, {1, 3, 1}, {2, 1, 1}};

    printf("Differenza delle diagonali: %d\n", diffDiagonali(matrice, 0, N));

    return 0;
}

int diffDiagonali(Matrice mat, int indice, int dimensione) {
    int principale, secondaria;

    if (dimensione == 0 || dimensione == 1) {
        return 0;
    }

    principale = mat[indice][indice] + mat[indice+dimensione-1][indice+dimensione-1];
    secondaria = mat[indice][indice+dimensione-1] + mat[indice+dimensione-1][indice];

    return principale - secondaria + diffDiagonali(mat, indice + 1, dimensione - 2);
}
