#include <stdio.h>
#include <math.h>

int main() {
    double a,b,c;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 0;
    double x=a,y=b,z=c;
    if (x<y){ double t=x;x=y;y=t;} if (x<z){ double t=x;x=z;z=t;} if (y<z){ double t=y;y=z;z=t;}
    a = x; b = y; c = z;
    if (b + c <= a) { printf("Nao forma triangulo\n"); return 0; }
    // classificacao lados
    if (a==b && b==c) printf("Equilatero\n");
    else if (a==b || b==c || a==c) printf("Isosceles\n");
    else printf("Escaleno\n");
    double asq = a*a, rest = b*b + c*c;
    if (fabs(asq - rest) < 1e-9) printf("Retangulo\n");
    else if (asq < rest) printf("Acutangulo\n");
    else printf("Obtusangulo\n");
    return 0;
}
