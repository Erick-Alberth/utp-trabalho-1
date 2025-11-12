#include <stdio.h>

void imprime_horario(int h, int m, int formato12) {
    h = (h % 24 + 24) % 24;
    m = (m % 60 + 60) % 60;
    if (!formato12) {
        printf("%02d:%02d\n", h, m);
    } else {
        int hour = h % 12;
        if (hour == 0) hour = 12;
        printf("%02d:%02d %s\n", hour, m, (h < 12) ? "AM" : "PM");
    }
}

int main() {
    int h,m,fmt;
    if (scanf("%d %d %d", &h, &m, &fmt) != 3) return 0;
    int dh[5] = {0, 1, 2, 4, 12};
    int dm[5] = {0, 0, 10, 40, 5};
    for (int i=0;i<5;i++) {
        int nh = h + dh[i];
        int nm = m + dm[i];
        nh += nm / 60;
        nm = nm % 60;
        imprime_horario(nh, nm, fmt);
    }
    return 0;
}
