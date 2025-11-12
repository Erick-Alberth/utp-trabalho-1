#include <stdio.h>
#include <math.h>

int main() {
    float x, y, max_teia;
    int n;
    if (scanf("%f %f", &x, &y) != 2) return 0;
    if (scanf("%f", &max_teia) != 1) return 0;
    if (scanf("%d", &n) != 1) return 0;
    int consegue = 1;
    for (int i = 0; i < n; i++) {
        float ax, ay;
        scanf("%f %f", &ax, &ay);
        float dx = ax - x;
        float dy = ay - y;
        float dist = sqrt(dx*dx + dy*dy);
        if (dist <= max_teia) {
            float nx = 2*ax - x;
            float ny = ay;
            x = nx; y = ny;
        } else {
            consegue = 0;
            for (int j = i+1; j < n; j++) {
                float tx, ty; scanf("%f %f", &tx, &ty);
            }
            break;
        }
    }
    if (consegue) printf("S\n"); else printf("N\n");
    return 0;
}
