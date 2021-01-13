#include <stdio.h>
#include <stdlib.h>

#define MAX 8

char* stringaMatricola(int matricola);

int main() {
  int matricola = 1234567;
  char* strMat;
  FILE* file;
  int i;
  int tuttiContenuti;
  char c;

  file = fopen("input.txt", "r");

  strMat = stringaMatricola(matricola);

  if (file != NULL) {
    c = fgetc(file);
    while (c != EOF) {
      for (i = 0; i < MAX; i++) {
        printf("%d) %c, %c\n", i + 1, strMat[i], c);

        if (strMat[i] == c) {
          strMat[i] = '\0';
        }
      }

      c = fgetc(file);
    }

    tuttiContenuti = 1;
    for (i = 0; i < MAX; i++) {
      if (strMat[i] != '\0') {
        tuttiContenuti = 0;
      }
    }

    if (tuttiContenuti) {
      printf("OK\n");
    } else {
      printf("KO\n");
    }

    fclose(file);
  } else {
    printf("KO\n");
  }

  return 0;
}

char* stringaMatricola(int matricola) {
  char* strMat = malloc(MAX * sizeof(char));

  sprintf(strMat, "%d", matricola);

  return strMat;
}