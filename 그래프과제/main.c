#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000001
#define ITERATIONS 5

void selectionSort(int list[], int n);
void swap(int* a, int* b);
void printExecutionTime(int listSize, double duration);

int main() {
    int i, j;
    int list[MAX_SIZE];
    int sizelist[] = { 1000, 5000, 10000, 50000, 100000 };
    clock_t start, stop;
    double duration;

    printf("Selection Sort\n");
    for (i = 0; i < ITERATIONS; i++) {
        for (j = 0; j < sizelist[i]; j++)
            list[j] = sizelist[i] - j;

        start = clock();
        selectionSort(list, sizelist[i]);
        stop = clock();

        duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
        printExecutionTime(sizelist[i], duration);
    }

    return 0;
}

void selectionSort(int list[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[minIndex])
                minIndex = j;
        }
        swap(&list[i], &list[minIndex]);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printExecutionTime(int listSize, double duration) {
    printf("List Size: %d, Duration: %f seconds\n", listSize, duration);
}