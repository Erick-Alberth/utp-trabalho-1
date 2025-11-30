#include <stdio.h>
#include <string.h>

int main() {
    char palavra[21];
    scanf("%s", palavra);

    int indice;
    scanf("%d", &indice);

    if (palavra[indice] == 'x')
    {
        printf("Bum!");
    } else {
        int bombas = 0;
        if (indice - 1 >= 0 && palavra[indice - 1] == 'x' ) bombas++;
        if (indice + 1 < strlen(palavra) && palavra[indice + 1] == 'x') bombas++;
        
        printf("%d", bombas);
    }
    
    return 0;
}