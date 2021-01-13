#include <stdio.h>

int main() {
    int numero;
    char nomeFile[] = "MultipliDiXY.txt";
    FILE* file = NULL;
    int i;

    printf("Inserisci un numero da 1 a 99: ");
    scanf("%d", &numero);

    nomeFile[10] = numero / 10 + '0';
    nomeFile[11] = numero % 10 + '0';

    file = fopen(nomeFile, "w");

    for (i = 1; i <= 10; i++) {
        fprintf(file, "%d ", numero * i);
    }

    fclose(file);

    return 0;
}
