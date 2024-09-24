#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct ListNode {
    int num;
    struct ListNode *next;
} ListNode;

ListNode *newListNode(int num)
{
    ListNode *node = malloc(sizeof(ListNode));
    node->num = num;
    node->next = NULL;
    return node;
}

typedef struct LinkedListQueue {
    ListNode *front;
    ListNode *rear;
    int size;
} LinkedListQueue;

LinkedListQueue *newLinkedListQueue() {
    LinkedListQueue *q = malloc(sizeof(LinkedListQueue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void delLinkedListQueue(LinkedListQueue *q) {
    while (q->front != NULL) {
        ListNode *tmp = q->front;
        q->front = q->front->next;
        free(tmp);
    }
    free(q);
}

int size(LinkedListQueue *q) {
    return q->size;
}

bool isEmpty(LinkedListQueue *q) {
    return size(q) == 0;
}

void push(LinkedListQueue *q, int num) {
    ListNode *node = newListNode(num);

    if (isEmpty(q)) {
        q->rear = node;
        q->front = node;
    }
    else {
        q->rear->next = node;
        q->rear = node;
    }
    q->size++;
}

int peek(LinkedListQueue *q) {
    if (isEmpty(q)) {
        printf("Empty stack. \n");
        return INT8_MAX;
    }
    return q->front->num;
}

int pop(LinkedListQueue *q) {
    if (isEmpty(q)) {
        printf("Empty stack. \n");
        return INT8_MAX;
    }
    int val = peek(q);
    ListNode *tmp = q->front;
    q->front = q->front->next;
    free(tmp);
    q->size--;

    return val;
}

int main(void) {
    LinkedListQueue *q = newLinkedListQueue();
    push(q, 1);
    push(q, 2);
    push(q, 3);
    push(q, 4);
    push(q, 5);

    ListNode *tmp = q->front;
    while (tmp != NULL) {
        printf("Queue index val: %i \n", tmp->num);
        tmp = tmp->next;
    }

    printf("Peek: %i", peek(q));
}



