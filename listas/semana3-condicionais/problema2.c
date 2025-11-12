#include <stdio.h>

int main() {
    char tipo;
    float consumo;
    if (scanf("%f %c", &consumo, &tipo) != 2) return 0;
    float preco;
    if (tipo == 'R' || tipo == 'r') preco = 0.60f;
    else if (tipo == 'C' || tipo == 'c') preco = 0.48f;
    else if (tipo == 'I' || tipo == 'i') preco = 1.29f;
    else return 0;
    float total = consumo * preco + 15.00f;
    printf("%.2f\n", total);
    return 0;
}