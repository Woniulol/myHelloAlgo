#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

const int MAX_CAP = 100;

typedef struct ArrayStack {
    int *data;
    int size;
} ArrayStack;

ArrayStack *newArrayStack() {
    ArrayStack *s = malloc(sizeof(ArrayStack));
    s->data = malloc(sizeof(int) * MAX_CAP);
    s->size = 0;
    return s;
}

void delArrayStack(ArrayStack *s) {
    free(s->data);
    free(s);
}

int size(ArrayStack *s) {
    return s->size;
}

bool isEmpty(ArrayStack *s) {
    return size(s) == 0;
}

void push(ArrayStack *s, int num) {
    if (s->size == MAX_CAP) {
        printf("Stack is full. \n");
        return;
    }
    s->data[s->size] = num;
    s->size++;
}

int peek(ArrayStack *s) {
    if (isEmpty(s))
    {
        printf("Empty Stack.\n");
        return INT8_MAX;
    }
    return s->data[s->size - 1];
}

int pop(ArrayStack *s) {
    int val = peek(s);
    s->size--;
    return val;
}

int main(void)
{
    ArrayStack *s = newArrayStack();
    push(s, 1);
    push(s, 3);
    push(s, 2);
    push(s, 5);
    push(s, 4);

    for (int i = 0; i < size(s); i++)
    {
        printf("Stack index %i: %i \n", i, s->data[i]);
    }

    printf("Stack peek: %i \n", peek(s));
    printf("Stack pop: %i \n", pop(s));

    for (int i = 0; i < size(s); i++)
    {
        printf("Stack index %i: %i \n", i, s->data[i]);
    }

    printf("Is Stack empty: %i \n", isEmpty(s));
}

