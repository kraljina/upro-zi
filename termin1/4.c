#include <stdio.h>

struct record {
    int code;
    int salary;
    char name[40 + 1];
};

struct record zapis;
struct record najgori;

void increaseLowest(char *fileName, int percentage) {
    int indexNajmanji = 0;
    int najmanjaPlaca = 100000000;

    FILE *bin = fopen(fileName, "r+b");
    int i = 0;
    while (fread(&zapis, sizeof(zapis), 1, bin)) {
        if (zapis.salary < najmanjaPlaca) {
            najmanjaPlaca = zapis.salary;
            indexNajmanji = i;
            najgori = zapis;
        }
        i++;
    }
    najgori.salary = najgori.salary * (1 + percentage * 1.0f / 100);
    fseek(bin, sizeof(zapis) * indexNajmanji, SEEK_SET);
    fwrite(&najgori, sizeof(zapis), 1, bin);
    fclose(bin);
}

int main(void) {
    increaseLowest("salaries.bin", 15);
    FILE *bin = fopen("salaries.bin", "r+b");
    while (fread(&zapis, sizeof(zapis), 1, bin)) {
        printf("%s %d\n", zapis.name, zapis.salary);
    }
}