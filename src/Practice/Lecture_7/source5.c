#include <stdio.h>

struct myS {
    int a;
    char c;
};

void handlerStructs (struct myS * State, struct myS * State2) {
    State->a = State2->a /2;
    State->c = ++State2->c;

    printf("%d %c\n", State->a, State->c);
}

int main() {
    struct  myS State[10];
    State[0].a = 100500;
    State[0].c = 'A';

    printf("%d %c\n", State[0].a, State[0].c);

    for (int j = 1; j < 10; ++j) {
        handlerStructs(& State[j], & State[j - 1]);
    }

    return 0;
}