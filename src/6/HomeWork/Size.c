#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *F;
    F = fopen("/home/crevan/Документы/C-C-Qt-course/src/6/HomeWork/In/test.txt", "rt");
    if (!F) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    char sym;
    int count = 0;
    while (fread((char *) &sym, sizeof(char), 1, F))
        count++;

    printf("Размер считанных данных: %d байт", count);

    fclose(F);
    return 0;
}