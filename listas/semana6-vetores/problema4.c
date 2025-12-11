#include <stdio.h>

int main() {
    int v[10];
    for (int i=0;i<10;i++) if (scanf("%d", &v[i])!=1) return 0;
    int visit[10] = {0};
    int cur = 0;
    while (!visit[cur]) {
        visit[cur] = 1;
        cur = v[cur];
    }
    printf("%d\n", cur);
    return 0;
}
