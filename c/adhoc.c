#include <stdio.h>
#include "include/arrayTest.h"

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(&arr[min_index], &arr[i]);
        }
    }
}

void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                swap(&arr[j], &arr[i]);
            }
        }
    }
}

void insertSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i+1; (j-1 >= 0) && (arr[j] < arr[j-1]); j--) {
            swap(&arr[j-1], &arr[j]);
        }
    }
}

int main(void) {
    int size;
    int* arr = randomSizeOneDigitArray(&size);

    // selectionSort(arr, size);
    // bubbleSort(arr, size);
    insertSort(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%i, ", arr[i]);
    }
}