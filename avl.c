#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

/* Max of two integers */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/* Height of node */
int height(struct Node *N) {
    if (N == NULL) return 0;
    return N->height;
}

/* Create new node */
struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

/* Right rotate */
struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

/* Left rotate */
struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

/* Get balance factor */
int getBalance(struct Node *N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
}

/* Insert node in AVL tree */
struct Node* insertAVL(struct Node* node, int value) {
    if (node == NULL) return createNode(value);

    if (value < node->data)
        node->left = insertAVL(node->left, value);
    else if (value > node->data)
        node->right = insertAVL(node->right, value);
    else
        return node; // Duplicate values not allowed

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

/* Inorder Traversal */
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Main Program */
int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter node %d: ", i + 1);
        scanf("%d", &value);
        root = insertAVL(root, value);
    }

    printf("\nInorder Traversal of AVL Tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
