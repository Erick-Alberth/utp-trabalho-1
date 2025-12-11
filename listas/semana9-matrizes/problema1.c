#include <stdio.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int m[10][10];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &m[i][j]);
        }
    }

    int coberto = 0, nao = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] == 1) {
                int ok = 0;
                if (i > 0 && m[i-1][j] == 2) ok = 1;
                if (i < M-1 && m[i+1][j] == 2) ok = 1;
                if (j > 0 && m[i][j-1] == 2) ok = 1;
                if (j < N-1 && m[i][j+1] == 2) ok = 1;

                if (ok) coberto++;
                else nao++;
            }
        }
    }

    printf("%d %d\n", coberto, nao);
    return 0;
}