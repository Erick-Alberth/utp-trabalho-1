#include <stdio.h>

int main() {
    int chuva[12];
    char *meses[] = {"Janeiro","Fevereiro","Marco","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
    for(int i = 0; i < 12; i++) scanf("%d", &chuva[i]);

    for(int i = 0; i < 12; i++) {
        int maior = i;
        for(int j = i + 1; j < 12; j++)
            if(chuva[j] > chuva[maior])
                maior = j;

        int temp = chuva[i];
        chuva[i] = chuva[maior];
        chuva[maior] = temp;

        char *t = meses[i];
        meses[i] = meses[maior];
        meses[maior] = t;
    }

    for(int i = 0; i < 12; i++)
        printf("%s %d\n", meses[i], chuva[i]);

    return 0;
}