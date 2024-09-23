#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * Dynamic array
 * 1. Initial capacity
 * 2. Size Recording
 * 3. Expansion mechanism
 */

// MyList Struct
typedef struct MyList
{
    int *arr;
    int capacity;
    int size;
    int extendRatio;
} MyList;

// Init Function
MyList *newMyList() {
    MyList *nums = malloc(sizeof(MyList));
    nums->capacity = 10;
    nums->arr = malloc(sizeof(int) * nums->capacity);
    nums->size = 0;
    nums->extendRatio = 2;
    return nums;
}

// Delete MyList Object
void delMyList(MyList *nums) {
    free(nums->arr);
    free(nums);
}

// Get the size of a MyList Object
int size(MyList *nums) {
    return nums->size;
}

// Get the capacity of a MyList Object
int capacity(MyList *nums) {
    return nums->capacity;
}

// Get the val of the index
int get(MyList *nums, int index) {
    assert(index >= 0 && index < nums->size);
    return nums->arr[index];
}

// Set the val on the index
void set(MyList *nums, int index, int num) {
    assert(index >= 0 && index < nums->size);
    nums->arr[index] = num;
}

// Expand Capacity
void extendCapacity(MyList *nums)
{
    int newCapacity = capacity(nums) * nums->extendRatio;
    int *newArr = malloc(sizeof(int) * newCapacity);
    int *tmp = nums->arr;

    for (int i = 0; i < size(nums); i++) {
        newArr[i] = tmp[i];
    }
    free(tmp);

    nums->arr = newArr;
    nums->capacity = newCapacity;
}

void add(MyList *nums, int num)
{
    if (size(nums) == capacity(nums))
    {
        extendCapacity(nums);
    }
    nums->arr[size(nums)] = num;
    nums->size++;
}

void insert(MyList *nums, int index, int num)
{
    assert(index >= 0 && index < size(nums));
    if (size(nums) == capacity(nums))
    {
        extendCapacity(nums);
    }
    for (int i = size(nums) - 1 ; i <= index; i--)
    {
        nums->arr[i] = nums->arr[i-1];
    }
    nums->arr[index] = num;
    nums->size++;
}

void removeItem(MyList *nums, int index)
{
    assert(index >= 0 && index < size(nums));
    for (int i = index; i < size(nums) - 1; i++)
    {
        nums->arr[i] = nums->arr[i+1];
    }
    nums->size--;
}

int *toArray(MyList *nums)
{
    return nums->arr;
}

int main(void)
{
    MyList *nums = newMyList();

    add(nums, 1);
    add(nums, 3);
    add(nums, 2);
    add(nums, 5);
    add(nums, 4);
    printf("Size of list: %i \n", size(nums));

    insert(nums, 3, 100);
    for (int i = 0; i < size(nums); i++)
    {
        printf("Index %i: %i \n", i, toArray(nums)[i]);
    }
    printf("Size of list: %i \n", size(nums));
    printf("=============\n");

    removeItem(nums, 2);
    for (int i = 0; i < size(nums); i++)
    {
        printf("Index %i: %i \n", i, toArray(nums)[i]);
    }
    printf("Size of list: %i \n", size(nums));
    printf("=============\n");

    set(nums, 0, 100);
    for (int i = 0; i < size(nums); i++)
    {
        printf("Index %i: %i \n", i, toArray(nums)[i]);
    }
    printf("Size of list: %i \n", size(nums));
    printf("=============\n");

    for (int i = 0; i < 20; i++)
    {
        add(nums, i);
    }
    set(nums, 0, 100);
    for (int i = 0; i < size(nums); i++)
    {
        printf("Index %i: %i \n", i, toArray(nums)[i]);
    }
    printf("Size of list: %i \n", size(nums));
    printf("Capacity of list: %i \n", capacity(nums));
    printf("=============\n");
}

