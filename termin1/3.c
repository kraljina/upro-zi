#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generirajLozinku(unsigned int sjeme, const char *znakoviZaLozinku,
                      int duljLoz, char *lozinka) {
    srand(sjeme);
    int duljNiza = strlen(znakoviZaLozinku);
    int duljina = 0;
    while (duljina < duljLoz) {
        char c = rand() % duljNiza;
        lozinka[duljina] = znakoviZaLozinku[c];
        duljina++;
    }
    lozinka[duljina] = '\0'; 
}

int main(void) {
    char lozinka[10];

    char niz[100] = "123456789qwertzuiopasdfghjklyxcvbnmQWERTZUIOPASDFGHJKLYXCVBNM#$&()";

    generirajLozinku(
        500,
        niz,
        10, lozinka);

    printf("%s", lozinka);

    return 0;
}