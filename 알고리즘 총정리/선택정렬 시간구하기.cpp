#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the elements
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
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
    selectionSort(numbers1, size1);
    clock_t end = clock();
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers1: %.6f seconds\n", timeTaken);

    // Measure time for sorting numbers2
    start = clock();
    selectionSort(numbers2, size2);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers2: %.6f seconds\n", timeTaken);

    // Measure time for sorting numbers3
    start = clock();
    selectionSort(numbers3, size3);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers3: %.6f seconds\n", timeTaken);

    // Measure time for sorting numbers4
    start = clock();
    selectionSort(numbers4, size4);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers4: %.6f seconds\n", timeTaken);

    // Measure time for sorting numbers5
    start = clock();
    selectionSort(numbers5, size5);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers5: %.6f seconds\n", timeTaken);

    return 0;
}