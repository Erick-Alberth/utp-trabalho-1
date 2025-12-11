#include <stdio.h>

int main() {
    int a, b, i, j, primo;
    scanf("%d %d", &a, &b);

    for(i = a; i <= b; i++) {
        if(i < 2) continue;
        primo = 1;
        for(j = 2; j*j <= i; j++) {
            if(i % j == 0) {
                primo = 0;
                break;
            }
        }
        if(primo) printf("%d ", i);
    }
    return 0;
}