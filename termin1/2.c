#include <math.h>
#include <stdio.h>

typedef struct {
    double x;
    double y;
} tocka_t;

tocka_t *pokNaNajblizuTocku(tocka_t *tocka, int n) {
    int najbliza = 0;
    double minUdaljenost = __DBL_MAX__;

    for (int i = 0; i < n; i++) {
        double udaljenost =
            sqrt(pow((*(tocka + i)).x, 2) + pow((*(tocka + i)).y, 2));

        if (udaljenost <= minUdaljenost) {
            if (udaljenost != 0) {
                minUdaljenost = udaljenost;
                najbliza = i;
            }
        }

        // printf("%lf\n", udaljenost);
    }
    return (tocka + najbliza);
}

int main(void) {
    tocka_t tocke[10] = {
        {2.e+121, 2.e+121}, {1.e+121, 1.e+121}, {4.e+121, 4.e+121}};

    tocka_t *pok = pokNaNajblizuTocku(tocke, 5);

    printf("%lf %lf", (*pok).x, (*pok).y);
}