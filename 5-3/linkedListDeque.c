#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct DoublyListNode {
    int num;
    struct DoublyListNode *next;
    struct DoublyListNode *prev;
} DoublyListNode;

DoublyListNode *newDoublyListNode(int num) {
    DoublyListNode *new = malloc(sizeof(DoublyListNode));
    new->num = num;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void delDoublyListNode(DoublyListNode *node) {
    free(node);
}

typedef struct LinkedListDeque {
    DoublyListNode *front;
    DoublyListNode *rear;
    int qSize;
} LinkedListDeque;

LinkedListDeque *newLinkedListDeque() {
    LinkedListDeque *q = malloc(sizeof(LinkedListDeque));
    q->front = NULL;
    q->rear = NULL;
    q->qSize = 0;
    return q;
}

void delLinkedListDeque(LinkedListDeque *q) {
    for (int i = 0; i < q->qSize && q->front != NULL; i++) {
        DoublyListNode *tmp = q->front;
        q->front = q->front->next;
        free(tmp);
    }
    free(q);
}

int size(LinkedListDeque *q) {
    return q->qSize;
}

bool empty(LinkedListDeque *q) {
    return size(q) == 0;
}

void push(LinkedListDeque *q, int num, bool isFront) {
    DoublyListNode *node = newDoublyListNode(num);
    if (size(q) == 0) {
        q->front = node;
        q->rear = node;
    }
    else if (isFront) {
        q->front->prev = node;
        node->next = q->front;
        q->front = node;
    }
    else {
        q->rear->next = node;
        node->prev = q->rear;
        q->rear = node;
    }
    q->qSize++;
}

void pushFirst(LinkedListDeque *q, int num) {
    push(q, num, true);
}

void pushLast(LinkedListDeque *q, int num) {
    push(q, num, false);
}

int pop(LinkedListDeque *q, bool isFront) {
    assert(size(q) > 0);
    int val;
    if (isFront) {
        int val = q->front->num;
        DoublyListNode *newFront = q->front->next;
        if (newFront) {
            newFront->prev = NULL;
            q->front->next = NULL;
        }
        free(q->front);
        q->front = newFront;
    }
    else {
        int val = q->rear->num;
        DoublyListNode *newRear= q->rear->prev;
        if (newRear) {
            newRear->next = NULL;
            q->rear->prev = NULL;
        }
        free(q->rear);
        q->rear = newRear;
    }
    q->qSize--;
    return val;
}