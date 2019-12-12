#include <stdio.h>
#define BLOCK 3

int main() {

#if BLOCK == 2
    printf("%d\n", BLOCK);
#endif

    return 0;
}