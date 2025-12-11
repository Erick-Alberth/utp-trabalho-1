#include <stdio.h>
#include <stdlib.h>

int *buscaNoVetor(int *v, int n, int valor, int *qtd) {
    *qtd = 0;

    for (int i = 0; i < n; i++)
        if (v[i] == valor) (*qtd)++;

    if (*qtd == 0) return NULL;

    int *ind = malloc(*qtd * sizeof(int));
    int k = 0;

    for (int i = 0; i < n; i++)
        if (v[i] == valor) ind[k++] = i;

    return ind;
}

int main() {
    int n;
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    int valor;
    scanf("%d", &valor);

    int qtd;
    int *res = buscaNoVetor(v, n, valor, &qtd);

    if (res == NULL) {
        printf("Nenhuma ocorrencia\n");
        free(v);
        return 0;
    }

    printf("%d\n", qtd);
    for (int i = 0; i < qtd; i++) printf("%d", res[i]);

    free(v);
    free(res);
    return 0;
}