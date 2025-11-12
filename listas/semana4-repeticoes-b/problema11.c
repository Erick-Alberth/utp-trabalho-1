#include <stdio.h>

int main() {
    int a, b, c, d, valido = 1;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if(a == b || a == c || a == d || b == c || b == d || c == d)
        valido = 0;
    if(a - b == 1 || b - a == 1 || a - c == 2 || c - a == 2 ||
       a - d == 3 || d - a == 3 || b - c == 1 || c - b == 1 ||
       b - d == 2 || d - b == 2 || c - d == 1 || d - c == 1)
        valido = 0;

    printf(valido ? "valido\n" : "invalido\n");
    return 0;
}
