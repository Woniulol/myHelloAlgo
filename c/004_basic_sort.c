#include <stdio.h>

/**
 * Selection Sort
 * In [i: n-1], find the smallest and put in i, continue in [i+1: n-1]
 *
 * Bubble Sort
 * In [0: i], find the larger one with neighbor, where the largest will come to i,
 * continue in [0: i-1]
 *
 * Insert Sort
 * Sorted in [0: i], compare new comer from right to left, insert when no longer
 * smaller than. Continue
 */

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection_sort(int *arr, int size) {
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

void bubble_sort(int *arr, int size) {
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0 ; j < i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void insert_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j - 1 >= 0; j--) {
            if (arr[j] < arr[j-1]) {
                swap(&arr[j], &arr[j-1]);
            }
        }
    }
}

int main(void) {
    int size = 7;
    int arr[] = {3, 4, 2, 5, 6, 1, 0};
    int *p  = &arr[0];

    // selection_sort(p, size);
    // bubble_sort(p, size);
    insert_sort(p, size);

    for (int i = 0; i < size; i++) {
        printf("%i", arr[i]);
    }
}


