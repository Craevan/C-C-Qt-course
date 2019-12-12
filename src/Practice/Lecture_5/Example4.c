#include <stdio.h>

int main() {
    int a[2] = {2321, 3214};

    int *pi = 0;
    int *pi2 = &a[0];
    pi = pi2;
    printf("%d\n", *pi);

    pi = pi + 1; // работаем c указателем

    printf("%p\n", *pi);
    printf("%d\n", *pi);
    printf("%d\n", pi);

    return 0;
}