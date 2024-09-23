#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode *newListNode(int val) {
    ListNode *node = malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void insert(ListNode *node, ListNode *newNode) {
    newNode->next = node->next;
    node->next = newNode;
}

/**
 * Delete the node after a specific node, not the node itself.
 */
void delete(ListNode *node) {
    if (node->next == NULL) {
        return;
    }
    ListNode *to_delete = node->next;
    node->next = to_delete->next;
    free(to_delete);
}

int search(ListNode *node, int val) {
    ListNode *tmp = node;
    int index = 0;
    while (tmp != NULL) {
        if (tmp->val == val) {
            return index;
        }
        tmp = tmp->next;
        index++;
    }
    return -1;
}

int main(void) {
    ListNode *node0 = newListNode(0);
    ListNode *node1 = newListNode(1);
    ListNode *node2 = newListNode(2);
    ListNode *node3 = newListNode(3);
    ListNode *node4 = newListNode(4);

    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    insert(node1, newListNode(100));
    delete(node0);

    ListNode *tmp = node0;
    while (tmp != NULL) {
        printf("Val: %i \n", tmp->val);
        tmp = tmp->next;
    }

    int search_target = 100;
    int search_res = search(node0, search_target);
    printf("index for %i: %i", search_target, search_res);
}

