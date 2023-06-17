#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int* array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);

        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

void generateRandomNumbers(int* array, int size, int upperBound) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % upperBound + 1;
    }
}

int main() {
    const int size1 = 1000;
    const int size2 = 5000;
    const int size3 = 10000;
    const int size4 = 50000;
    const int size5 = 100000;

    int numbers1[size1];
    int numbers2[size2];
    int numbers3[size3];
    int numbers4[size4];
    int numbers5[size5];

    // Generate random numbers
    generateRandomNumbers(numbers1, size1, 1000);
    generateRandomNumbers(numbers2, size2, 5000);
    generateRandomNumbers(numbers3, size3, 10000);
    generateRandomNumbers(numbers4, size4, 50000);
    generateRandomNumbers(numbers5, size5, 100000);

    // Measure time for sorting numbers1
    clock_t start = clock();
    quickSort(numbers1, 0, size1 - 1);
    clock_t end = clock();
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers1: %.6f seconds\n", timeTaken);

    // Measure time for sorting numbers2
    start = clock();
    quickSort(numbers2, 0, size2 - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers2: %.6f seconds\n", timeTaken);

    // Measure time for sorting numbers3
    start = clock();
    quickSort(numbers3, 0, size3 - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers3: %.6f seconds\n", timeTaken);

    // Measure time for sorting numbers4
    start = clock();
    quickSort(numbers4, 0, size4 - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers4: %.6f seconds\n", timeTaken);

    // Measure time for sorting numbers5
    start = clock();
    quickSort(numbers5, 0, size5 - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers5: %.6f seconds\n", timeTaken);

    return 0;
}