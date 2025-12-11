#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    return sin(cos(y) + x) + cos(y + sin(x));
}

int ponto_seguro(double x, double y) {
    double p = f(x,y);
    if (p <= 0.0 || p >= 2.0) return 0;
    double p1 = f(x+0.2, y+0.2);
    double p2 = f(x-0.2, y-0.2);
    double p3 = f(x+0.2, y-0.2);
    double p4 = f(x-0.2, y+0.2);
    if (p1 <= 0.0 || p1 >= 2.0) return 0;
    if (p2 <= 0.0 || p2 >= 2.0) return 0;
    if (p3 <= 0.0 || p3 >= 2.0) return 0;
    if (p4 <= 0.0 || p4 >= 2.0) return 0;
    return 1;
}

int main() {
    double x,y;
    if (scanf("%lf %lf", &x, &y) != 2) return 0;
    if (!ponto_seguro(x,y)) { printf("troque de coordenada\n"); return 0; }
    int seguros = 0;
    if (ponto_seguro(x+2,y)) seguros++;
    if (ponto_seguro(x-2,y)) seguros++;
    if (ponto_seguro(x,y+2)) seguros++;
    if (ponto_seguro(x,y-2)) seguros++;
    if (seguros <= 1) printf("inseguro\n");
    else if (seguros <= 3) printf("relativamente seguro\n");
    else printf("seguro\n");
    return 0;
}