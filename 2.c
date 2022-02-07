#include <stdio.h>

struct vektor_s {
    int komp_i;
    int komp_j;
};

void SumaVektora(struct vektor_s *pok, int n, struct vektor_s *rez) {
    (*rez).komp_i = 0;
    (*rez).komp_j = 0;
    for (int i = 0; i < n; i++) {
        (*rez).komp_i += (*(pok + i)).komp_i;
        (*rez).komp_j += (*(pok + i)).komp_j;
    }
}

int main(void) {
    struct vektor_s rez = {0, 0};
    struct vektor_s vektori[7] = {{1, -3}, {-2, 8}, {4, 5}, {3, -14},
                                  {2, 2},  {6, -6}, {1, -1}};

    SumaVektora(vektori, 7, &rez);

    printf("%d %d", rez.komp_i, rez.komp_j);

    return 0;
}