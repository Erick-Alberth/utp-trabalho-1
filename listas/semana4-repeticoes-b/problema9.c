#include <stdio.h>

int main() {
    int n, i, qtd, total = 0;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &qtd);
        if(qtd > 10) total += qtd - 10;
    }

    printf("%d\n", total);
    return 0;
}