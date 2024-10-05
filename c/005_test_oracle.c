/**
 * 1. You want to test a solution to ensure the algorithm is correct.
 * 2. You can implement another algorithm to solve the same problem but probably
 * bad in time and space complexity.
 * 3. You also need to implement a test case generator.
 * 4. Compare the result between the two algorithm to ensure the result are the same.
 * 5. When the sample population is large enough, you should be confident the
 * solution is correct.
 *
 * The critical point is step 4, to find a sample whose size is small be contains
 * error sample.
 */

#include <stdlib.h>
#include <stdio.h>

int *randomArray(int size) {
    int min = 0;
    int max = 10;
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
    return arr;
}

int *copyArray(int size, int *arr) {
    int *arrCopy = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arrCopy[i] = arr[i];
    }
    return arrCopy;
}

int main(void) {
    int size = 10;

    int *arr = randomArray(size);
    for (int i = 0; i < size; i++){
        printf("%i", arr[i]);
    }
    printf("\n");

    int *arrCopy = copyArray(size, arr);
    for (int i = 0; i < size; i++){
        printf("%i", arrCopy[i]);
    }
    printf("\n");

    /**
     * For each sort method, use the same test sample to test
     * and then check if the result is the same or not.
     */
}