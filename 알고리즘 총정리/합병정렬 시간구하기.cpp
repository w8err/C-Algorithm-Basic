#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* array, int left, int middle, int right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int* leftArray = (int*)malloc(leftSize * sizeof(int));
    int* rightArray = (int*)malloc(rightSize * sizeof(int));

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArray[j] = array[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    free(leftArray);
    free(rightArray);
}

void mergeSort(int* array, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
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
    mergeSort(numbers1, 0, size1 - 1);
    clock_t end = clock();
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers1: %.6f seconds\n", timeTaken);

    // Measure time for sorting numbers2
    start = clock();
    mergeSort(numbers2, 0, size2 - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers2: %.6f seconds\n", timeTaken);

    // Measure time for sorting numbers3
    start = clock();
    mergeSort(numbers3, 0, size3 - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers3: %.6f seconds\n", timeTaken);

    // Measure time for sorting numbers4
    start = clock();
    mergeSort(numbers4, 0, size4 - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers4: %.6f seconds\n", timeTaken);

    // Measure time for sorting numbers5
    start = clock();
    mergeSort(numbers5, 0, size5 - 1);
    end = clock();
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort numbers5: %.6f seconds\n", timeTaken);

    return 0;
}