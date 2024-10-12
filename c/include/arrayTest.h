#ifndef ARRAYTEST_H
#define ARRAYTEST_H

#include <stdlib.h>
#include <stdio.h>

int* randomSizeOneDigitArray(int* size) {
    *size = (int) rand() % (1<<10);
    int max = 9, min = 0;
    int* arr = (int*) malloc(*size * sizeof(int));
    for (int i = 0; i < *size; i++) {
        arr[i] = min + (rand() % (max - min + 1));
    }
    return arr;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

#endif