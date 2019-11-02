#include <stdio.h>

int main() {
    int a[3][2] = {2321, 3214,
                   23, 25,
                   52, 3425};

    int *pi = 13;
    int *pi2 = &a[1][1];
    int **pipi = &pi;
    pi = pi2;
    printf("%d\n", **pipi);

//    pi = pi + 1; // работаем c указателем
//
//    printf("%p\n", *pi);
//    printf("%d\n", *pi);
//    printf("%d\n", pi);

    return 0;
}