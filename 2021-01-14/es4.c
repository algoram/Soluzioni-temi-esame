#include <stdio.h>

int main() {
  FILE* fileA;
  FILE* fileB;
  FILE* unione;

  float numA, numB;

  fileA = fopen("A.txt", "r");
  fileB = fopen("B.txt", "r");
  unione = fopen("unione.txt", "w");

  if (fileA && fileB && unione) {
    fscanf(fileA, "%f", &numA);
    fscanf(fileB, "%f", &numB);

    if (numA < numB) {
      while (!feof(fileA)) {
        fprintf(unione, "%f\n", numA);
        fscanf(fileA, "%f", &numA);
      }

      while (!feof(fileB)) {
        fprintf(unione, "%f\n", numB);
        fscanf(fileB, "%f", &numB);
      }
    } else {
      while (!feof(fileB)) {
        fprintf(unione, "%f\n", numB);
        fscanf(fileB, "%f", &numB);
      }

      while (!feof(fileA)) {
        fprintf(unione, "%f\n", numA);
        fscanf(fileA, "%f", &numA);
      }
    }

    fclose(fileA);
    fclose(fileB);
    fclose(unione);
  } else {
    printf("Errore nell'apertura dei file\n");
  }

  return 0;
}