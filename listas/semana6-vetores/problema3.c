#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int v[31];
    for (int i=0;i<n;i++) scanf("%d", &v[i]);
    int max = v[0];
    for (int i=1;i<n;i++) if (v[i] > max) max = v[i];
    int first=-1, second=-1;
    for (int i=0;i<n;i++){
        if (v[i]==max) {
            if (first==-1) first=i;
            else if (second==-1) { second=i; break; }
        }
    }
    printf("%d\n", second - first);
    return 0;
}
