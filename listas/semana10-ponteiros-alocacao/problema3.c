#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *misturar(char *str1, char *str2) {
    int n1 = strlen(str1), n2 = strlen(str2);
    char *r = malloc(n1 + n2 + 1);

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        r[k++] = str1[i++];
        r[k++] = str2[j++];
    }

    while (i < n1) r[k++] = str1[i++];
    while (j < n2) r[k++] = str2[j++];

    r[k] = '\0';
    return r;
}

int main() {
    char s1[101], s2[101];
    fgets(s1, 101, stdin);
    fgets(s2, 101, stdin);

    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';

    char *r = misturar(s1, s2);
    printf("%s\n", r);

    free(r);
    return 0;
}