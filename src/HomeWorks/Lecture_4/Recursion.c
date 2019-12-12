#include <stdio.h>

int recursionSum();

int main() {
    int date = 0;
    printf("%s\n", "Введите дату вашего рождения");
    scanf("%d", &date);
    printf("%s = %d", "Сумма цифр даты Вашего рождения", recursionSum(date));
    return 0;
}

int recursionSum(int a){
    return (a > 0) ? a % 10 + recursionSum(a / 10) : 0;
}
