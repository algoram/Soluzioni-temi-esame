#include <stdio.h>

void RicBubbleSort(float Arr[], int N);

int main() {
  int i;
  float array[] = {3.0, 2.0, 1.0, 4.0};

  RicBubbleSort(array, 4);

  for (i = 0; i < 4; i++) {
    printf("%f ", array[i]);
  }
  printf("\n");

  return 0;
}

void RicBubbleSort(float Arr[], int N) {
  int i;
  float temp;

  if (N == 1) return;

  for (i = 0; i < N - 1; i++) {
    if (Arr[i] > Arr[i + 1]) {
      temp = Arr[i];
      Arr[i] = Arr[i + 1];
      Arr[i + 1] = temp;
    }
  }

  RicBubbleSort(Arr, N - 1);
}