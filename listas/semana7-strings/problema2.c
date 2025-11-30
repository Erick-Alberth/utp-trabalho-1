#include <stdio.h>
#include <string.h>

int ehLetra(char c) {return c >= 'A' && c <= 'Z'; }
int ehNumero(char c) {return c >= '0' && c <= '9'; }

int main() {
    char placa[11];
    scanf("%s", placa);

    //placa brasileira-->
    if (strlen(placa) == 8 &&
        ehLetra(placa[0]) &&
        ehLetra(placa[1]) &&
        ehLetra(placa[2]) &&
        placa[3] == '-' &&
        ehNumero(placa[4]) &&
        ehNumero(placa[5]) &&
        ehNumero(placa[6]) &&
        ehNumero(placa[7])
    ) {
        printf("brasileiro");
    } else if (strlen(placa) == 7 &&
               ehLetra(placa[0]) &&
               ehLetra(placa[1]) &&
               ehLetra(placa[2]) &&
               ehNumero(placa[3]) &&
               ehLetra(placa[4]) &&
               ehNumero(placa[5]) &&
               ehNumero(placa[6])
    ) {
        printf("mercosul");
    } else {
        printf("inválido");
    }

    return 0;
}

