#include <stdio.h>
#include <stdlib.h>

typedef struct Array
{
    int *arr;
    int size_t;
} Array;

Array *newArray(int *nums, int size)
{
    Array *arr = malloc(sizeof(Array));
    arr->arr = malloc(sizeof(nums[0]) * size);
    for (int i = 0; i < size; i++)
    {
        arr->arr[i] = nums[i];
    }
    arr->size_t = size;
    return arr;
}

void selectionSort(Array *arr)
{
    for (int i = 0; i < arr->size_t; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < arr->size_t; j++)
        {
            if (arr->arr[j] < arr->arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int tmp = arr->arr[i];
            arr->arr[i] = arr->arr[min_index];
            arr->arr[min_index] = tmp;
        }
    }
}

void selectionSortPointer(Array *arr)
{
    int *p = arr->arr;
    for (int i = 0; i < arr->size_t; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < arr->size_t; j++)
        {
            if (*(p+j) < *(p+min_index))
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int tmp = *(p+i);
            *(p+i) = *(p+min_index);
            *(p+min_index) = tmp;
        }
    }
}

int main(void)
{
    int nums[ ] = { 2, 5, 3, 4, 1, 9, 0, 7, 8, 6 };
    Array *arr = newArray(nums, 10);
    // selectionSort(arr);
    selectionSortPointer(arr);
    for (int i = 0; i < arr->size_t; i++)
    {
        printf("%i", arr->arr[i]);
    }
}
