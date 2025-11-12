#include <stdio.h>

int main() {
    float valor;
    if (scanf("%f", &valor) != 1) return 0;
    float desconto = 0.0f;
    if (valor <= 100.0f) desconto = 0.0f;
    else if (valor <= 500.0f) desconto = 0.10f;
    else if (valor <= 1000.0f) desconto = 0.15f;
    else desconto = 0.20f;
    float valor_desconto = valor * desconto;
    float final = valor - valor_desconto;
    printf("%.2f\n%.2f\n%.0f%%\n", valor_desconto, final, desconto*100.0f);
    return 0;
}
