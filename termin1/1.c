#include <stdio.h>

void odrediMjesecIdanUskrsa(int godina, int *mjesec, int *dan) {
    int x, y = 0;
    if (godina >= 1582) {
        x = 22;
        y = 2;
    }
    if (godina >= 1700) {
        x = 23;
        y = 3;
    }
    if (godina >= 1800) {
        x = 23;
        y = 4;
    }
    if (godina >= 1900) {
        x = 24;
        y = 5;
    }

    int A = godina % 19;
    int B = godina % 4;
    int C = godina % 7;
    int D = (A * 19 + x) % 30;
    int E = (2 * B + 4 * C + 6 * D + y) % 7;

    if (22 + D + E < 31) {
        *mjesec = 3;
        *dan = 22 + D + E;
    } else {
        *mjesec = 4;
        *dan = D + E - 9;
    }
}

int main(void) {

    int mjesec, dan = 0;
    odrediMjesecIdanUskrsa(2050, &mjesec, &dan);
    printf("%d.%d.%d.", dan, mjesec, 2050);

    return 0;
}