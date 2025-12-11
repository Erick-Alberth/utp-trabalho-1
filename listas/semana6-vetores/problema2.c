#include <stdio.h>

int main() {
    int m,n;
    if (scanf("%d %d", &m, &n) != 2) return 0;
    int has[1001] = {0};
    for (int i=0;i<n;i++){
        int x; scanf("%d", &x);
        if (x>=1 && x<=m) has[x]=1;
    }
    int first = 1;
    for (int i=1;i<=m;i++){
        if (!has[i]) {
            if (!first) printf(" ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
