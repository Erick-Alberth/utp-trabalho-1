#include <stdio.h>
#include <ctype.h>

int main() {
    char a,b;
    if (scanf(" %c %c", &a, &b) != 2) return 0;
    a = toupper(a); b = toupper(b);
    if (a == b) { printf("Empate\n"); return 0; }
    if ((a=='P' && b=='T') || (a=='T' && b=='A') || (a=='A' && b=='P')) printf("Jogador 1\n");
    else printf("Jogador 2\n");
    return 0;
}
