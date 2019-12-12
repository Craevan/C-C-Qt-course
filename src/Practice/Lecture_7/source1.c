#include <stdio.h>
#define SUM(x,y) ((x) + (y))
#define KV(x) ((x) * (x))
#define SUMKV(x) SUM(x, x) \
                + KV(x)    \
                +(x+x)

int main() {
    printf("%d\n", SUM(100 * 333 + 1, 500));
    printf("%d\n", KV(1+2));
    printf("%d\n", SUMKV(2));
    return 0;
}