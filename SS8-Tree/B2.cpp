#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// tao nut moi
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// tim dinh theo lop
void printLevel2Nodes(Node* root, int currentLevel) {
    if (root == NULL) return;
    if (currentLevel == 2) {
        printf("%d ", root->data);
    } else if (currentLevel < 2) {
        printLevel2Nodes(root->left, currentLevel + 1);
        printLevel2Nodes(root->right, currentLevel + 1);
    }
}

int main() {
    Node* root = createNode(1);      
    root->left = createNode(2);      
    root->right = createNode(3);    
    root->left->left = createNode(4);  
    root->left->right = createNode(5); 
    root->right->left = createNode(6); 
    root->right->right = createNode(7);

    printf("Cac dinh lop 2: ");
    printLevel2Nodes(root, 0);
    printf("\n");

    return 0;
}

