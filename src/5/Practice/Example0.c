#include <stdio.h>
#define MAX_SIZE 5

int main() {
    int a[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; ++i) {
        a[i] = i;
        printf("a[%d] = %d\n" , i, a[i]);
    }
    return 0;
}