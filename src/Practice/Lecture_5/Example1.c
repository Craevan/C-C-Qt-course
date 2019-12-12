#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int main() {
    int a[MAX_SIZE][MAX_SIZE - 1];
    for (int x = 0; x < MAX_SIZE; ++x) {
        for (int y = 0; y < MAX_SIZE - 1; ++y) {
            a[x][y] = (char) (rand()%256-127);
            printf("a[%d][%d]=%c \n", x, y, a[x][y]);
        }
    }
    return 0;
}