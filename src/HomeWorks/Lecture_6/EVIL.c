#include <stdio.h>

int main(void)
{
    int i = 0;
    Counting:
    printf("%d ",++i);
    if (i<100)
        goto Counting;
    return 0;
}