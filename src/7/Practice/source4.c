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

    struct myS cur2;
    cur2 = curS;
    printf("%d %s\n", cur2.i, cur2.s);

    return 0;
}