#include <stdio.h>

int main() {
    int firstCount = 2;
    int secondCount = 5;
    do {
        printf("%s = %d\n", "firstCount", firstCount);
        while (secondCount > 0){
            printf("%s = %d\n", "secondCount", secondCount);
            for (int i = 0; i < 10; ++i) {
                printf("%s = %d\n", "i", i);
            }
            secondCount--;
        }
        firstCount--;
    }
    while (firstCount > 0);
    return 0;
}