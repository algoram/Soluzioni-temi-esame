#include <stdio.h>

int cifraMassima(int n);

int main() {
    printf("%d", cifraMassima(799));

    return 0;
}

int cifraMassima(int n) {
    if (n == 0) {
        return 0;
    }

    int cifra = n % 10;
    int massimo = cifraMassima(n / 10);

    if (cifra > massimo) {
        return cifra;
    }

    return massimo;
}
