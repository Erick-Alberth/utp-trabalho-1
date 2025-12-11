#include <stdio.h>

int main() {
    float peso, altura, imc;
    if (scanf("%f %f", &peso, &altura) != 2) return 0;
    imc = peso / (altura * altura);
    printf("%.2f\n", imc);
    return 0;
}