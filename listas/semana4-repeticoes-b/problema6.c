#include <stdio.h>

int main() {
    int a, b, c, n;
    scanf("%d", &n);

    for(a = 1; a <= n; a++) {
        for(b = a; b <= n; b++) {
            for(c = b; c <= n; c++) {
                if(a*a + b*b == c*c)
                    printf("(%d, %d, %d)\n", a, b, c);
            }
        }
    }
    return 0;
}