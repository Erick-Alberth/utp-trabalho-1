#include <stdio.h>

int main() {
    float c;
    if (scanf("%f", &c) != 1) return 0;
    float f = (c * 9.0f/5.0f) + 32.0f;
    float k = c + 273.15f;
    printf("%.1f %.1f\n", f, k);
    return 0;
}