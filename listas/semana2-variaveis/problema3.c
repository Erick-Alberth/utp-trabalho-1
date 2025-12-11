#include <stdio.h>
#include <math.h>

int main() {
    double capital, taxa;
    int tempo;
    if (scanf("%lf %lf %d", &capital, &taxa, &tempo) != 3) return 0;
    double montante = capital * pow(1.0 + taxa/100.0, tempo);
    printf("%.2f\n", montante);
    return 0;
}