#include <stdio.h>

struct myS {
    int i;
    char * s;
};

int main() {
    struct  myS curS;
    curS.i = 100500;
    curS.s = "String";
    printf("%d %s\n", curS.i, curS.s);

    return 0;
}