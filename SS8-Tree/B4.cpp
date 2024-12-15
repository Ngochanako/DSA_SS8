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


int calculateHeightIterative(Node* root) {
    if (root == NULL) {
        return -1;
    }
    Node* queue[100]; 
    int front = 0, rear = 0;

    queue[rear++] = root; 
    int height = -1;

    while (front < rear) {
        int levelSize = rear - front; 
        height++; 
        for (int i = 0; i < levelSize; i++) {
            Node* current = queue[front++]; 
            if (current->left) {
                queue[rear++] = current->left;
            }
            if (current->right) {
                queue[rear++] = current->right;
            }
        }
    }

    return height;
}

int main() {
    Node* root = NULL;
    root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    int height = calculateHeightIterative(root);
    printf("Chieu cao cua cay la: %d\n", height);

    return 0;
}

