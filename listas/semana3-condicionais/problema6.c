#include <stdio.h>
#include <ctype.h>

int main() {
    char feb, dorc, dorn, tos;
    if (scanf(" %c %c %c %c", &feb, &dorc, &dorn, &tos) != 4) return 0;
    feb = toupper(feb); dorc = toupper(dorc); dorn = toupper(dorn); tos = toupper(tos);
    int f = (feb == 'S'), dh = (dorc == 'S'), db = (dorn == 'S'), t = (tos == 'S');
    if (f && dh && db) printf("Possivel gripe\n");
    else if (t && f) printf("Possivel resfriado\n");
    else if (!f && !t && dh && !db) printf("Possivel enxaqueca\n");
    else if (f && !dh && !db && !t) printf("Consulte um medico\n");
    else if (!f && !dh && !db && !t) printf("Voce parece estar bem\n");
    else printf("Consulte um medico para avaliacao\n");
    return 0;
}
