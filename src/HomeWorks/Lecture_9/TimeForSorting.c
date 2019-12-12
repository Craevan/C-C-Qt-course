#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 10000
#define COUNT_OF_STARTUP 10

int t_BubbleSort(int *arr);
int t_StdSort(int *arr);
int t_ShellSort(int *arr);
int compare(const int *i, const int *j);
int averageTime(int *arr);

int main() {

    srand(time(NULL));

    int array[ARRAY_SIZE];
    int bubbleArray[ARRAY_SIZE];
    int stdSortArray[ARRAY_SIZE];
    int shellArray[ARRAY_SIZE];

    int timesForBubbleSort[COUNT_OF_STARTUP];
    int timesForStdSort[COUNT_OF_STARTUP];
    int timesForShellSort[COUNT_OF_STARTUP];

    for (int cnt = 0; cnt < COUNT_OF_STARTUP; cnt++) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = 0 + rand() % 10;
            bubbleArray[i] = array[i];
            stdSortArray[i] = array[i];
            shellArray[i] = array[i];
        }
        timesForBubbleSort[cnt] = t_BubbleSort(bubbleArray);
        timesForStdSort[cnt] = t_StdSort(stdSortArray);
        timesForShellSort[cnt] = t_ShellSort(shellArray);
    }
    qsort(timesForBubbleSort, COUNT_OF_STARTUP, sizeof(int), (int (*)(const void *, const void *)) compare);
    qsort(timesForStdSort, COUNT_OF_STARTUP, sizeof(int), (int (*)(const void *, const void *)) compare);
    qsort(timesForShellSort, COUNT_OF_STARTUP, sizeof(int), (int (*)(const void *, const void *)) compare);

    printf("Время сортировки \"пузырьком\":\n");
    printf("Минимальное время: %d мкс\nСреднее время: %d мкс\nМаксимальное время: %d мкс\n\n", timesForBubbleSort[0],
           averageTime(timesForBubbleSort),
           timesForBubbleSort[COUNT_OF_STARTUP - 1]);

    printf("Время стандартной сортировки qsort:\n");
    printf("Минимальное время: %d мкс\nСреднее время: %d мкс\nМаксимальное время: %d мкс\n\n", timesForStdSort[0],
           averageTime(timesForStdSort),
           timesForStdSort[COUNT_OF_STARTUP - 1]);

    printf("Время сортивки \"Шелла\":\n");
    printf("Минимальное время: %d мкс\nСреднее время: %d мкс\nМаксимальное время: %d мкс\n", timesForShellSort[0],
           averageTime(timesForShellSort),
           timesForShellSort[COUNT_OF_STARTUP - 1]);

    return 0;
}

int compare(const int *i, const int *j) {
    return *i - *j;
}

int averageTime(int *arr){
    double avg = 0;
    for (int i = 0; i < COUNT_OF_STARTUP; i++)
        avg += arr[i];

    return (int) avg / COUNT_OF_STARTUP;
}

int t_BubbleSort(int *arr) {
    clock_t begin = clock();
    for (int i = 0; i < ARRAY_SIZE - 1; ++i) {
        for (int j = 0; j < ARRAY_SIZE - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }

    }
    clock_t end = clock();

    double time = ((double) (end - begin) / CLOCKS_PER_SEC) * 1000;

    return (int) time;
}

int t_StdSort(int * arr) {
    clock_t begin = clock();

    qsort(arr, ARRAY_SIZE, sizeof(int), (int (*) (const void *, const void *)) compare);
    clock_t end = clock();
    double time = ((double) (end - begin) / CLOCKS_PER_SEC) * 100000;

    return (int) time;
}

int t_ShellSort(int *arr) {
    int i, j, step, tmp;
    clock_t begin = clock();
    for (step = ARRAY_SIZE / 2; step > 0 ; step /= 2) {
        for (i = step; i < ARRAY_SIZE; ++i) {
            tmp = arr[i];
            for (j = i; j >= step ; j -= step) {
                if (tmp < arr[j - step])
                    arr[j] = arr[j -step];
                else
                    break;
            }
            arr[j] = tmp;
        }
    }
    clock_t end = clock();
    double time = ((double) (end - begin) / CLOCKS_PER_SEC) * 100000 ;

    return (int) time;
}