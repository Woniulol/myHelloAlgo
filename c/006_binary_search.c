#include <stdio.h>
#include <stdlib.h>

/**
 * As long as we can determine if one side definitely has or definitely does not have.
 * Then we can use binary search.
 */

/**
 * For a sorted array, determine if an element exist.
 */

int binary_search(int *arr, int size, int num){
    if (arr == NULL || size == 0) {
        return -1;
    }
    int left = 0, right = size - 1, middle = 0;
    // when left == right, still need to check if the single index is the target num;
    while (left <= right) {
        // Why not use (right + left) / 2?
        // right + left might overflow.
        middle = left + ((right - left) >> 1);
        if (arr[middle] ==  num) {
            return middle;
        }
        else if (arr[middle] > num) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return -1;
}

/**
 * Find the left most postion i where arr[i] >= num.
 * num may not be within arr.
 */
int binary_search_left_most_num(int *arr, int size, int num) {
    if (arr == NULL || size == 0) {
        return -1;
    }
    int left = 0, right = size - 1, middle = 0, left_most = -1;
    while (left <= right) {
        middle = left + ((right - left) >> 1);
        if (arr[middle] == num) {
            left_most = middle;
            return left_most;
        }
        else if (arr[middle] > num) {
            left_most = middle;
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return left_most;
}

int brutal_search(int *arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

/**
 * Binary Search does not have to be applied to an ordered array.
 *
 * E.g.
 * Define an arr of size, arr[-1] is -inf, arr[size] is also -inf.
 * Any element near each other is not the same.
 * If arr[i] > arr[i-1] && arr[i] > arr[i-1], return any of i.
 * arr does not have to be in order.
 *
 * [5,3,4,6,7,2,9,3,5]
 * Any of index 0, 4, 6, 8 can be returned.
 *
 * Implementation:
 * 1. Check index 0 and index size-1
 * 2. We know that in [0: 1] is increasing, and [size - 2: size - 1] is decreasing.
 * 3. There must be a point i between [1: size-2] where arr[i] > arr[i+1] and arr[i] > arr[i-1].
 * 4. Thus we check the middle point i, to see if it satisfy the condition.
 * 5. If not, we check [i-1: i] is decreasing or increasing.
 * 6. If is decreasing, target must be on the left hand, else on the right hand.
 *
 * LeetCode #162
 */
int findPeakElement(int* nums, int numsSize) {
    if ((numsSize == 1) || (nums[0] > nums[1])) {
        return 0;
    }
    if (nums[numsSize - 1] > nums[numsSize - 2]) {
        return numsSize - 1;
    }
    int left = 1, right = numsSize - 1, middle = 0;
    while (left <= right) {
        middle = left + ((right - left) >> 1);
        if (nums[middle] < nums[middle + 1]) {
            left = middle + 1;
        }
        else if (nums[middle] < nums[middle - 1]) {
            right = middle - 1;
        }
        else {
            // nums[middle] > nums[middle + 1] && nums[middle] > nums[middle - 1]
            return middle;
        }
    }
    return -1;
}


int main(void) {
    int size = 10;
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        int res = i * 2;
        printf("%i ", res);
        arr[i] = res;
    }

    printf("\n");
    printf("%i \n", binary_search(arr, size, 5));
    printf("%i \n", brutal_search(arr, size, 5));
    printf("%i \n", binary_search_left_most_num(arr, size, 30));

    int new_arr[] = {3, 2, 5, 1, 6, 2, 9, 3, 2};
    int* arr2 = &new_arr[0];
    int arr2Size = 9;
    printf("%i \n", binary_search_peak_value(arr2, arr2Size));
}
