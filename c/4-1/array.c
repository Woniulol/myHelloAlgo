#include <stdio.h>
#include <stdlib.h>

int randomAccess(int *nums, int size)
{
    int randomIndex = rand() % size;
    return nums[randomIndex];
}

/**
 * Insert num to index of nums of size size.
 */
void insert(int *nums, int size, int num, int index)
{
    // From last to the first, otherwise we lost the tract of the value being overwritten.
    for (int i = size; i >= index; i--)
    {
        nums[i] = nums[i-1];
    }
    nums[index] = num;
}

void delete(int *nums, int size, int index)
{
    for (int i = index; i < (size-1); i++)
    {
        nums[i] = nums[i+1];
    }
}

int *extend(int *nums, int size, int enlarge)
{
    int *res = malloc((size + enlarge) * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        res[i] = nums[i];
    }

    for (int i = size; i < size + enlarge; i++)
    {
        res[i] = 0;
    }

    return res;
}

int main(void)
{
    int arr[5] = { 0 };
    int nums[5] = { 1, 2, 3, 4, 5 };

    // Array support random access
    printf("Random Access: %i \n", randomAccess(nums, 5));
    printf("Random Access: %i \n", randomAccess(nums, 5));
    printf("Random Access: %i \n", randomAccess(nums, 5));

    insert(nums, 5, 100, 1);
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%i]: %i \n", i, nums[i]);
    }

    delete(nums, 5, 0);
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%i]: %i \n", i, nums[i]);
    }

    int *res = extend(nums, 5, 5);
    for (int i = 0; i < 10; i++)
    {
        printf("arr[%i]: %i \n", i, res[i]);
    }
}