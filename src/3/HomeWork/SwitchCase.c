#include <stdio.h>

int main() {
    int a;
    printf("%s\n", "Введите число от 0 до 9");
    scanf("%d", &a);
    switch (a) {
        case 0:
            printf("%s\n", "Н");
            break;
        case 1:
            printf("%s\n", "О");
            break;
        case 2:
            printf("%s\n", "Д");
            break;
        case 3:
            printf("%s\n", "Т");
            break;
        case 4:
            printf("%s\n", "Ч");
            break;
        case 5:
            printf("%s\n", "П");
            break;
        case 6:
            printf("%s\n", "Ш");
            break;
        case 7:
            printf("%s\n", "С");
            break;
        case 8:
            printf("%s\n", "В");
            break;
        case 9:
            printf("%s\n", "Д");
            break;
        default:
            printf("%s\n", "Введите цифру от 0 до 9");
    }
    return 0;
}