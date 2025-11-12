#include <stdio.h>
#include <math.h>

int ehprimo(int n) {
    if (n < 2) return 0;
    if (n==2) return 1;
    if (n%2==0) return 0;
    int r = sqrt(n);
    for (int i=3;i<=r;i+=2) if (n%i==0) return 0;
    return 1;
}

int main() {
    for (int x=3; x<=50000; x+=2) {
        if (ehprimo(x) && ehprimo(x+2) && ehprimo(x+6)) {
            printf("(%d, %d, %d)\n", x, x+2, x+6);
        }
    }
    return 0;
}