#include <stdio.h>
#include <math.h>

int main() {
    double a,b,c;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 0;
    if (a == 0.0) { printf("Nao eh equacao do segundo grau\n"); return 0; }
    double delta = b*b - 4*a*c;
    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2*a);
        double x2 = (-b - sqrt(delta)) / (2*a);
        printf("%.6f %.6f\n", x1, x2);
    } else if (delta == 0) {
        double x = -b / (2*a);
        printf("%.6f\n", x);
    } else {
        printf("Nao existem raizes reais\n");
    }
    return 0;
}