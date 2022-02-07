#include <stdio.h>
int nulovanje(int *polje, int m, int n) {
    int maxEl = *polje, maxRed, minStup;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (*(polje + n * i + j) > maxEl) {
                maxEl = *(polje + n * i + j);
                maxRed = i;
                minStup = j;
            }
            if (*(polje + n * i + j) == maxEl) {
                if (i > maxRed) {
                    maxEl = *(polje + n * i + j);
                    maxRed = i;
                    minStup = j;
                }
            }
        }
    }

    int suma = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == maxRed || minStup == j) {
                suma += *(polje + n * i + j);
                *(polje + n * i + j) = 0;
            }
        }
    }

    return suma;
}

int main(void) {

    int polje[2][5] = {{7, 2, 7, 5, 7}, {6, 7, 3, 7, -1}};

    int suma = nulovanje(&polje[0][0], 2, 5);

    printf("%d", suma);
    return 0;
}