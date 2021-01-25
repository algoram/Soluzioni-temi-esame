#include <stdio.h>

int periodica(char str[]);
int cercaPeriodo(char str[], char periodo[], int k);
int compare(char str[], char periodo[], int k);

int main() {
  char str[] = "ciaoc";

  int k = periodica(str);

  printf("Lunghezza periodo: %d\n", k);

  return 0;
}

int periodica(char str[]) {
  int k, i, j;
  int len;

  len = 0;
  while (str[len] != '\0') len++;

  for (k = 1; k <= len / 2; k++) {
    for (i = 0; i < len - k; i++) {
      if (cercaPeriodo(str + i, str + i, k) > 1) {
        printf("Periodo: ");
        for (j = 0; j < k; j++) {
          printf("%c", str[i + j]);
        }
        printf("\n");

        return k;
      }
    }
  }

  printf("La stringa non e' periodica\n");

  return 0;
}

int cercaPeriodo(char str[], char periodo[], int k) {
  if (*str == '\0') return 0;

  int res = compare(str, periodo, k);

  if (res > 0) {
    return 1 + cercaPeriodo(str + k, periodo, k);
  } else if (res < 0) {
    return -100;
  }

  return 0;
}

int compare(char str[], char periodo[], int k) {
  if (k == 0) return 1;
  if (*str == '\0') return 0;

  if (*str != *periodo) return -1;

  return compare(str + 1, periodo + 1, k - 1);
}