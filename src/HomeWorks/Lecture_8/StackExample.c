#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define COUNT_OF_TASKS 5

struct stack {
    int stk[COUNT_OF_TASKS];
    int top;                //num of last added elem
    int time[COUNT_OF_TASKS];
};

typedef struct stack MyStack;
MyStack myStack;

void push(void);
int popStack(void);
int popQue(void);
bool isAuto ();
void display(void);


int main() {
    srand(time(NULL));
    int choice = 0;
    myStack.top = 0;
    printf("Операции над стеком: \n");
    while (choice != 5) {
        printf("      1 Добавить задачу\n");
        printf("      2 Выполнить задачи (Стек)\n");
        printf("      3 Выполнить задачи (Очередь)\n");
        printf("      4 Показать список задач   \n");
        printf("      5 Выход\n");
        printf("\n");
        printf("Введите вариант: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                popStack();
                break;
            case 3:
                popQue();
                break;
            case 4:
                display();
                break;
            default:
                break;
        }
    }
    return 0;
}

// Добавление элементов в список

void push() {
    int count = 0;

    if (isAuto()) {
        printf("Сколько задач вы хотите добавить?(от 1 до %d задач)\n", COUNT_OF_TASKS);
        scanf("%d", &count);
        if ((count > COUNT_OF_TASKS) || (count <= 0))
        {
            printf("!!! Введите число от 0 до %d\n", COUNT_OF_TASKS);
            return;
        }
        for (int i = 1; i <= count; ++i)
        {
            myStack.top = myStack.top + 1;
            myStack.time[myStack.top] = 0 + rand() % 4;
            myStack.stk[myStack.top] = i;
        }
    }
    else {
        int num;
        if (myStack.top == (COUNT_OF_TASKS)) {
            printf("StackOverFlow!!! LOL\n");
            return;
        }
        else {
            printf("Введите имя задачи (Только числа!)\n");
            scanf("%d", &num);
            myStack.top = myStack.top + 1;
            int tmp;
            printf("Введите время её выполнения:\n");
            scanf("%d", &tmp);
            myStack.time[myStack.top] = tmp;
            myStack.stk[myStack.top] = num;
        }
        return;
    }
}

// Выполнение и удаление элемента из списка

int popQue() {
    if (myStack.top == 0) {
        printf("Список задач пуст!\n");
        return (myStack.top);
    }
    else {
        printf("Выбран алгоритм 'Очередь'\n");
        for (int i = 1; i <= myStack.top; i++) {
            printf("Выбрана задача № %d\n", myStack.stk[i]);
            printf("Задача будет длится %d секунд. Выполняю...\n", myStack.time[i]);
            sleep(myStack.time[i]);
        }
        myStack.top = 0;
    }

    return 0;
}

int popStack() {
    if (myStack.top == 0) {
        printf("Список задач пуст!\n");
        return (myStack.top);
    }
    else {
        printf("Выбран алгоритм 'Стек'\n");
        for (int i = myStack.top; i > 0; i--) {
            printf("Выбрана задача № %d\n", myStack.stk[i]);
            printf("Выполняю...\n");
            sleep(myStack.time[i]);
        }
        myStack.top = 0;
    }

    return (0);
}

void display() {
    if (myStack.top == 0) {
        printf("Список задач пуст!\n");
        return;
    }
    else {
        printf("\n Список задач: \n");
        for (int i = 1; i <= myStack.top; i++) {
            printf("Задача № %d, время выполнения - %d\n", myStack.stk[i], myStack.time[i]);
        }
    }
    printf("\n");
}

bool isAuto() {
    int ch=0;
    printf("0 - ввести все данные самостоятельно\n");
    printf("1 - ввести все данные автоматически\n");
    scanf("%d", &ch);
    return ch;
}