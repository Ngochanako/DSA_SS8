#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// chen cay nhi phan tim kiem
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// tim kiem
int search(Node* root, int key) {
    if (root == NULL) {
        return 0;
    }

    if (key == root->data) {
        return 1;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int key;
    printf("Nhap gia tri tim kiem: ");
    scanf("%d", &key);

    if (search(root, key)) {
        printf("Gia tri co ton tai trong cay.\n", key);
    } else {
        printf("Gia tri khong ton tai trong cây.\n", key);
    }

    return 0;
}

