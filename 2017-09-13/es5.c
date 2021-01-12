#include <stdio.h>

#define DIM 100

typedef int Immagine[DIM][DIM];

int perimetro(Immagine img, int w, int h); // w e h aggiunti per provare

int main() {
    Immagine img = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    printf("Il perimetro dell'oggetto e': %d\n", perimetro(img, 5, 5));

    return 0;
}

int perimetro(Immagine img, int w, int h) {
    int i, j;
    int coppie = 0;

    for (i = 1; i < h-1; i++) { // do per scontato che nei bordi esterni non ci sia l'oggetto
        for (j = 1; j < w-1; j++) {
            if (img[i][j] == 1 && img[i+1][j] == 0) coppie++;
            if (img[i][j] == 1 && img[i-1][j] == 0) coppie++;
            if (img[i][j] == 1 && img[i][j+1] == 0) coppie++;
            if (img[i][j] == 1 && img[i][j-1] == 0) coppie++;
        }
    }

    return coppie;
}
