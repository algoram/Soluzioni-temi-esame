#include <stdio.h>

int fileIdentici(char nomeFile1[], char nomeFile2[]);

int main() {
  if (fileIdentici("a.txt", "b.txt")) {
    printf("I file sono identici\n");
  } else {
    printf("I file non sono identici\n");
  }

  return 0;
}

int fileIdentici(char nomeFile1[], char nomeFile2[]) {
  FILE* file1;
  FILE* file2;
  char byte1, byte2;

  file1 = fopen(nomeFile1, "rb");
  file2 = fopen(nomeFile2, "rb");

  fread(&byte1, sizeof(char), 1, file1);
  fread(&byte2, sizeof(char), 1, file2);
  while (!feof(file1) && !feof(file2)) {
    if (byte1 != byte2) return 0;

    fread(&byte1, sizeof(char), 1, file1);
    fread(&byte2, sizeof(char), 1, file2);
  }

  if (feof(file1) && feof(file2)) {
    return 1;
  } else if (feof(file1)) {
    return 0;
  } else if (feof(file2)) {
    return 0;
  }
}