/*5) Busca em Árvore Binária de Busca (BST)
Dada uma árvore binária de busca, implemente uma função que receba
um valor e retorne se ele está ou não presente na árvore.*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
bool search(Node* root, int target) {
    if (root == NULL) {
        return false;
    }
    if (root->data == target) {
        return true;
    } else if (target < root->data) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    int target = 4;
    if (search(root, target)) {
        printf("Value %d found in the tree.\n", target);
    } else {
        printf("Value %d not found in the tree.\n", target);
    }

    target = 10;
    if (search(root, target)) {
        printf("Value %d found in the tree.\n", target);
    } else {
        printf("Value %d not found in the tree.\n", target);
    }

    freeTree(root);
    return 0;
}
