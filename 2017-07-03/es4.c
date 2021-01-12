#include <stdio.h>

#define MAX 500

int main() {
    int numCar = 0;
    char c;
    int occorrenze[256];
    int i;
    FILE* file = NULL;

    for (i = 0; i < 256; i++) {
        occorrenze[i] = 0;
    }

    file = fopen("input.txt", "r");

    c = fgetc(file);
    while (numCar < MAX && c != EOF) {
        numCar++;

        occorrenze[c]++;

        c = fgetc(file);
    }

    fclose(file);

    file = fopen("output.txt", "w");

    for (i = 'z'; i >= 'a'; i--) {
        if (occorrenze[i] > 0) {
            fprintf(file, "%c%d\n", i, occorrenze[i]);
        }
    }

    fclose(file);

    return 0;
}
