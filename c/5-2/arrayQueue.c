#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct ArrayQueue {
    int *nums; // Array to hold all values
    int front; // Front pointer
    int qSize; // Size of the queue
    int qCapacity; // Queue Capacity
} ArrayQueue;

ArrayQueue *newArrayQueue(int capacity) {
    ArrayQueue *q = malloc(sizeof(ArrayQueue));
    q->qCapacity = capacity;
    q->nums = malloc(sizeof(int) * q->qCapacity);
    q->front = 0;
    q->qSize = 0;
    return q;
}

void delArrayQueue(ArrayQueue *q) {
    free(q->nums);
    free(q);
}

int capacity(ArrayQueue *q) {
    return q->qCapacity;
}

int size(ArrayQueue *q) {
    return q->qSize;
}

bool isEmpty(ArrayQueue *q) {
    return size(q) == 0;
}

int peek(ArrayQueue *q) {
    assert(!isEmpty(q));
    return q->nums[q->front];
}

int rearIndex(int front, int size, int capacity) {
    return (front + size) % capacity;
}

void push(ArrayQueue *q, int num) {
    if (q->qSize == q->qCapacity) {
        printf("Queue is full. \n");
        return;
    }
    q->nums[rearIndex(q->front, q->qSize, q->qCapacity)] = num;
    // After push, we only update size, not front.
    q->qSize++;
}

int pop(ArrayQueue *q) {
    int val = peek(q);
    q->front = q->front++ % q->qCapacity;
    q->qSize--;
    return val;
}
