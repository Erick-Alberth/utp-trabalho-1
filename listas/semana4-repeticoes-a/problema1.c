#include <stdio.h>

int main() {
    float comprimento, largura, bolso;
    if (scanf("%f %f %f", &comprimento, &largura, &bolso) != 3) return 0;
    int dobras = 0;
    while (comprimento > bolso && largura > bolso) {
        if (comprimento > largura) comprimento /= 2.0f;
        else largura /= 2.0f;
        dobras++;
    }
    printf("%d\n", dobras);
    return 0;
}
