#include <stdio.h>

int main() {
    float n1,n2,n3;
    if (scanf("%f %f %f", &n1, &n2, &n3) != 3) return 0;
    float media = (n1 + n2 + n3) / 3.0f;
    if (media >= 7.0f) {
        printf("aprovado\n");
    } else if (media < 4.0f) {
        printf("reprovado\n");
    } else {
        // recuperacao
        float nota_final_necessaria = 10.0f;
        nota_final_necessaria = 10.0f - media;
        if (nota_final_necessaria < 0.0f) nota_final_necessaria = 0.0f;
        printf("recuperacao\n%.2f\n", nota_final_necessaria);
    }
    return 0;
}
