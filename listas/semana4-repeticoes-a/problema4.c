#include <stdio.h>
#include <math.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int total = 0;
    for (int i = 0; i < n; i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        double r = sqrt(x*x + y*y);
        if (r <= 1.0) total += 10;
        else if (r <= 5.0) total += 5;
        else if (r <= 10.0) total += 1;
        else total += 0;
    }
    printf("%d\n", total);
    return 0;
}
