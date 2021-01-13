#include <stdio.h>

#define MAX 25

int main(int argc, char** argv) {
  FILE* input = fopen(argv[1], "r");
  FILE* output = fopen(argv[2], "w");
  char c = argv[3][0];
  int k, i;
  char temp[MAX + 1];
  int cont;

  sscanf(argv[4], "%d", &k);

  fscanf(input, "%s", temp);
  while (!feof(input)) {
    cont = 0;
    i = 0;

    while (temp[i] != '\0') {
      if (temp[i] == c) {
        cont++;
      }

      i++;
    }

    if (cont >= k) {
      fprintf(output, "%s\n", temp);
    }

    fscanf(input, "%s", temp);
  }

  fclose(input);
  fclose(output);

  return 0;
}