#include <stdio.h>

int main() {
    float peso, altura, imc;
    if (scanf("%f %f", &peso, &altura) != 2) return 0;
    imc = peso / (altura * altura);
    if (imc < 18.5f) printf("Abaixo do peso\n");
    else if (imc <= 24.9f) printf("Peso normal\n");
    else if (imc <= 29.9f) printf("Sobrepeso\n");
    else printf("Obesidade\n");
    return 0;
}