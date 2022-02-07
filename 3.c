#include <stdio.h>
#include <stdlib.h>

void igra(int seed, int brojBacanja, int *pobjednik, int *razlika) {
    srand(seed);

    int sumaPrvi = 0;
    int sumaDrugi = 0;
    for (int i = 0; i < brojBacanja; i++) {
        int prvi = rand() % 6 + 1;
        int drugi = rand() % 6 + 1;

        sumaPrvi += prvi;
        sumaDrugi += drugi;
    }

    if (sumaPrvi > sumaDrugi) {
        *pobjednik = 1;
        *razlika = sumaPrvi - sumaDrugi;
    } else if (sumaDrugi > sumaPrvi) {
        *pobjednik = 2;
        *razlika = sumaDrugi - sumaPrvi;
    } else {
        *pobjednik = 0;
        *razlika = 0;
    }
}

int main(void) {

    int pobjednik, razlika;
    igra(123, 3, &pobjednik, &razlika);

    printf("%d %d", pobjednik, razlika);

    return 0;
}