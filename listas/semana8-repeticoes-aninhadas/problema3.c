#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int largada[n], chegada[n], pos[21];
    for(int i = 0; i < n; i++) scanf("%d", &largada[i]);
    for(int i = 0; i < n; i++) scanf("%d", &chegada[i]);

    for(int i = 1; i <= n; i++) pos[i] = 0;

    for(int i = 0; i < n; i++)
        pos[largada[i]] = i;

    int melhor = 0, maiorGanho = 0, empate = 0;

    for(int i = 0; i < n; i++) {
        int piloto = chegada[i];
        int ganho = pos[piloto] - i;

        if(ganho > maiorGanho) {
            maiorGanho = ganho;
            melhor = piloto;
            empate = 0;
        } else if(ganho == maiorGanho && ganho > 0) {
            empate = 1;
        }
    }

    if(maiorGanho == 0 || empate) printf("empate\n");
    else printf("%d\n", melhor);

    return 0;
}