#include <stdio.h>

enum A {a, b = -99, c};
enum B {a1, b1 = -97, c1};
int main() {
    printf("%s %d %d\n", a1, b, c);
    return 0;
}