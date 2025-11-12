#include <stdio.h>

int main() {
    int n, preco, soma = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &preco);
        soma += preco;
    }

    if(n >= 3) soma -= preco / 2;
    printf("%d\n", soma);

    return 0;
}
