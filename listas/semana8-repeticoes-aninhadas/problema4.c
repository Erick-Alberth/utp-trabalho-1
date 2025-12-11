#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);

    int p[10][10];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &p[i][j]);
        }
    }

    int X, Z;
    scanf("%d %d", &X, &Z);

    int direto = p[X][Z];
    int melhor = direto;
    int via = -1;

    for (int y = 0; y < M; y++) {
        if (y != X && y != Z) {
            int custo = p[X][y] + p[y][Z];
            if (melhor == 0 || (custo > 0 && custo < melhor)) {
                melhor = custo;
                via = y;
            }
        }
    }

    if (via == -1)
        printf("%d-%d R$%d\n", X, Z, melhor);
    else
        printf("%d-%d-%d R$%d\n", X, via, Z, melhor);

    return 0;
}