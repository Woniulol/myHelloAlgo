#include <stdlib.h>
#include <stdio.h>

const int MAX_SIZE = 100;

typedef struct TreeNode {
    int val;
    int height;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *newTreeNode(int val) {
    TreeNode *node = malloc(sizeof(TreeNode));
    node->val = val;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Level-order Traversal (Breath-first Search BFS)
 */

int *levelOrder(TreeNode *root, int *size) {
    int front;
    int rear;
    int index;
    int *arr;

    // Init queue.
    TreeNode *node;
    TreeNode **queue; // queue of pointers of tree node
    queue = malloc(sizeof(TreeNode *) * MAX_SIZE);
    front = 0, rear = 0;

    // Push root to the queue.
    queue[rear++] = root;

    // Array to hold result
    arr = malloc(sizeof(int) * MAX_SIZE);
    index = 0;

    while (front < rear) {
        node = queue[front++];
        arr[index++] = node->val;

        if (node->left != NULL) {
            queue[rear++] = node->left;
        }

        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }

    *size = index;
    arr = realloc(arr, sizeof(index) * (*size));

    free(queue);
    return arr;
}



