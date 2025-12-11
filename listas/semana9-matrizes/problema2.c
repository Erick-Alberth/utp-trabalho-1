#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);

    int a[100][100];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

    int x;
    scanf("%d", &x);

    for (int j = 0; j < M; j++) {
        if (j != x && a[x][j] == 0) {
            int comum = 0;
            for (int k = 0; k < M; k++) {
                if (a[x][k] == 1 && a[j][k] == 1) {
                    comum = 1;
                    break;
                }
            }
            if (comum) printf("%d ", j);
        }
    }

    return 0;
}
