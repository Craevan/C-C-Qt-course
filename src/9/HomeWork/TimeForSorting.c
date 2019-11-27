#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 10000

int t_BubbleSort(int *arr);
int stdSort(int * arr);
int minSort(int *arr);
int compare(const int *i, const int *j);

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

    double time = (double) (end - begin) / CLOCKS_PER_SEC * 1000;

    return (int) time;
}

int stdSort(int * arr) {
    clock_t begin = clock();

    qsort(arr, ARRAY_SIZE, sizeof(int), (int (*) (const void *, const void *)) compare);
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC * 1000;

    return (int) time_spent;
}