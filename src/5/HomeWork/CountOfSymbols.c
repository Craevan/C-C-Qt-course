#include <stdio.h>
#include <string.h>


unsigned Freq[256];


int main( void )
{
    char *Name;
    FILE *F;

    printf("Введите имя файла >> ");
    scanf("%s", Name);
    if ((F = fopen(Name, "rt")) == NULL)
    {
        fprintf(stderr, "Невозможно открыть для чтения файл '%s'\n", Name);
        return 1;
    }

    memset(Freq, 0, 256 * sizeof(unsigned));

    while (!feof(F))
        Freq[fgetc(F)] ++;

    fclose(F);

    printf("Частоты появления символов:\n");
    for (int i = 0; i < 256; ++i) {
        if (Freq[i])
            printf("Символ %c : %5u раз\n", i, Freq[i]);
    }

    return 0;

}