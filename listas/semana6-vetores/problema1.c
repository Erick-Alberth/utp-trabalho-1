#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int gabarito[20];
    for (int i=0;i<n;i++) scanf("%d", &gabarito[i]);
    int resp[20];
    for (int i=0;i<n;i++) scanf("%d", &resp[i]);
    int ac = 0;
    for (int i=0;i<n;i++) if (gabarito[i] == resp[i]) ac++;
    if (ac == 1) printf("1 acerto\n");
    else printf("%d acertos\n", ac);
    return 0;
}