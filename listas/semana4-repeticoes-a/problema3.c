#include <stdio.h>

int somaDivisores(int n) {
    int soma = 0;
    for (int i = 1; i <= n/2; i++) if (n % i == 0) soma += i;
    return soma;
}

int main() {
    int A, B;
    if (scanf("%d %d", &A, &B) != 2) return 0;
    int DA = somaDivisores(A);
    int DB = somaDivisores(B);
    int cond = (DA - B >= -2 && DA - B <= 2) && (DB - A >= -2 && DB - A <= 2);
    if (cond) printf("S\n"); else printf("N\n");
    return 0;
}
