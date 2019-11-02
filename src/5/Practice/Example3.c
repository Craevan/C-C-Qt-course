#include <stdio.h>

int main() {
    int iVal = 1024;
    int *pi = 0;
    int *pi2 = &iVal;
    pi = pi2;
    *pi = *pi + 2; // работаем со значением
    pi2 = 0;

    printf("%p\n", *pi);
    printf("%d\n", *pi);
    printf("%d\n", pi);

    pi = pi + 2; // работаем с указателем

    printf("%p\n", *pi);
    printf("%d\n", *pi);
    printf("%d\n", pi);

    return 0;
}