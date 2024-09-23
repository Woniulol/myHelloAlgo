#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * A stack class implemented based on linked list.
 */

typedef struct ListNode
{
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

typedef struct LinkedListStack
{
    ListNode *top;
    int size;
} LinkedListStack;

LinkedListStack *newLinkedListStack(void)
{
    LinkedListStack *s = malloc(sizeof(LinkedListStack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void delLinkedListStack(LinkedListStack *s)
{
    while (s->top)
    {
        ListNode *tmp = s->top->next;
        free(s->top);
        s->top = tmp;
    }
    free(s);
}

int size(LinkedListStack *s)
{
    return s->size;
}

bool isEmpty(LinkedListStack *s)
{
    return size(s) == 0;
}

void push(LinkedListStack *s, int num)
{
    ListNode *n = newListNode(num);
    n->next = s->top;
    s->top = n;
    s->size++;
}

int peek(LinkedListStack *s)
{
    if (s->size == 0)
    {
        printf("Empty Stack \n");
        return INT8_MAX;
    }
    return s->top->num;
}

int pop(LinkedListStack *s)
{
    int val = peek(s);

    ListNode *tmp = s->top;
    s->top = s->top->next;
    free(tmp);

    s->size--;

    return val;
}

int *toArray(LinkedListStack *s)
{
    int *arr = malloc(sizeof(int) * size(s));

    ListNode *tmp = s->top;
    int i = 0;

    while (tmp)
    {
        arr[i] = tmp->num;
        tmp = tmp->next;
        i++;
    }

    return arr;
}

int main(void)
{
    LinkedListStack *s = newLinkedListStack();
    push(s, 1);
    push(s, 3);
    push(s, 2);
    push(s, 5);
    push(s, 4);

    for (int i = 0; i < size(s); i++)
    {
        printf("Stack index %i: %i \n", i, toArray(s)[i]);
    }

    printf("Stack peek: %i \n", peek(s));
    printf("Stack pop: %i \n", pop(s));

    for (int i = 0; i < size(s); i++)
    {
        printf("Stack index %i: %i \n", i, toArray(s)[i]);
    }

    printf("Is Stack empty: %i \n", isEmpty(s));
}


