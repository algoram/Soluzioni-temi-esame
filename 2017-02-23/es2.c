#include <stdio.h>

#define MAX 101

void copiaStringa(char dst[], char src[]);

int main(int argc, char** argv) {
    int caratteriTotali = 0;
    int lineeTotali = 0;
    int massimoLinea = 0;
    int lunghezzaLinea = 0;
    int spaziMassimi = 0;
    int numeroSpazi = 0;
    char linea[MAX];
    char lineaMassima[MAX];
    char carattere;

    FILE* file = fopen(argv[1], "r");

    carattere = fgetc(file);
    while (carattere != EOF) {
        if (carattere != '\n') {
            linea[lunghezzaLinea++] = carattere;

            if (carattere != ' ') {
                caratteriTotali++;
            } else {
                numeroSpazi++;
            }
        } else {
            lineeTotali++;
            linea[lunghezzaLinea] = '\0';

            if (lunghezzaLinea > massimoLinea) {
                massimoLinea = lunghezzaLinea;
                spaziMassimi = numeroSpazi;
                copiaStringa(lineaMassima, linea);
            }

            lunghezzaLinea = 0;
            numeroSpazi = 0;
        }


        carattere = fgetc(file);
    }

    fclose(file);

    printf("Linee: %d\n", lineeTotali);
    printf("Caratteri: %d\n", caratteriTotali);
    printf("Max, Med: %d, %d\n", massimoLinea - spaziMassimi, caratteriTotali / lineeTotali);
    printf("Linea max: %s\n", lineaMassima);

    return 0;
}

void copiaStringa(char dst[], char src[]) {
    while (*src != '\0') {
        *dst = *src;

        dst++;
        src++;
    }

    *dst = '\0';
}
