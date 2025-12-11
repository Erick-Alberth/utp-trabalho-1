#include <stdio.h>

int main() {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) return 0;
    int soma = a + b;
    int dif = a - b;
    long prod = (long)a * b;
    float div = (float)a / (float)b;
    int resto = a % b;
    float media = (a + b) / 2.0f;
    printf("%d\n%d\n%ld\n%.6f\n%d\n%.6f\n", soma, dif, prod, div, resto, media);
    return 0;
}