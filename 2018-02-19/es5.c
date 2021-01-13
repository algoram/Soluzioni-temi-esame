#include <stdio.h>

// per compilare: gcc Programma.c -o Test.exe
// per eseguire: Test.exe Prova.txt (WINDOWS)

int main(int argc, char** argv) {
  FILE* file;
  char c;

  file = fopen(argv[1], "r");

  c = fgetc(file);
  while (c != EOF) {
    printf("%c", c);

    c = fgetc(file);
  }

  fclose(file);

  return 0;
}