#include <stdio.h>
#include <stdlib.h>

int *alocarVetor(int n) {
    return malloc(n * sizeof(int));
}

int *somaVetores(int *u, int *v, int n) {
    int *r = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) r[i] = u[i] + v[i];
    return r;
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int *u = alocarVetor(n1);
    int *v = alocarVetor(n2);

    for (int i = 0; i < n1; i++) scanf("%d", &u[i]);
    for (int i = 0; i < n2; i++) scanf("%d", &v[i]);

    if (n1 != n2) {
        printf("dimensoes incompativeis\n");
        free(u);
        free(v);
        return 0;
    }

    int *s = somaVetores(u, v, n1);

    for (int i = 0; i < n1; i++) printf("%d ", s[i]);

    free(u);
    free(v);
    free(s);
    return 0;
}
