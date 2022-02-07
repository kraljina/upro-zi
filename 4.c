#include <stdio.h>

struct record {
    int code;
    int x;
    int y;
};

struct record zapis;

_Bool txt2bin(char *inputFile, char *outputFile) {
    FILE *txt = fopen(inputFile, "r");
    FILE *bin = fopen(outputFile, "wb");

    if(txt == NULL || bin == NULL) return 0;

    while (fscanf(txt, "%2d%3d%3d", &zapis.code, &zapis.x, &zapis.y) != EOF) {
        fseek(bin, (long)(zapis.code-1)*sizeof(zapis), SEEK_SET);
        fwrite(&zapis, sizeof(zapis), 1, bin);
    }
    fclose(txt);
    fclose(bin);

    return 1;
}

int main(void) {
    _Bool test = txt2bin("input.txt", "out.bin");
    FILE *bin = fopen("out.bin", "rb");
    while (fread(&zapis, sizeof(zapis), 1, bin)) {
        printf("%d %d %d\n", zapis.code, zapis.x, zapis.y);
    }
    printf("%d", test);
    return 0;
}