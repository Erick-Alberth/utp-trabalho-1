#include <stdio.h>
#include <string.h>
#include <ctype.h>
//formato data
int eh_data(const char *s) {
    return isdigit(s[0]) && isdigit(s[1]) &&
           s[2] == '/' &&
           isdigit(s[3]) && isdigit(s[4]);
}

int main() {
    char aluno[11];
    char rel[1001];

    fgets(aluno, sizeof(aluno), stdin);
    aluno[strcspn(aluno, "\n")] = '\0';

    fgets(rel, sizeof(rel), stdin);
    rel[strcspn(rel, "\n")] = '\0';

    int ausencias = 0;
    int i = 0, n = strlen(rel);

    while (i < n) {
        if (!eh_data(&rel[i])) {
            i++;
            continue;
        }

        i += 6;

        int presente = 0;

        while (i < n && !eh_data(&rel[i])) {
            char nome[20];
            int k = 0;

            while (i < n && rel[i] != ' ' && k < 19)
                nome[k++] = rel[i++];

            nome[k] = '\0';

            while (i < n && rel[i] == ' ')
                i++;

            if (strcmp(nome, aluno) == 0)
                presente = 1;
        }

        if (!presente)
            ausencias++;
    }

    printf("%d\n", ausencias);
    return 0;
}