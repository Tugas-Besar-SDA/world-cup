#include "headerRizki.h"

int tree_height(int n) {
    return (int)(log2(n+1)-1);
}

addressNode create_node(int number) {
    addressNode newNode = (addressNode) malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->value = number;
    newNode->gol = 0;
    newNode->right = NULL;
    return newNode;
}

addressNode build_tree(int arr[], int start, int end) {
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    addressNode root = create_node(arr[mid]);
    root->left = build_tree(arr, start, mid - 1);
    root->right = build_tree(arr, mid + 1, end);
    return root;
}

void preorder_traversal(addressNode root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(addressNode root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->value);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(addressNode root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->value);
    }
}
