#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int isCompleteBinaryTree(Node* root) {
    if (root == NULL) return 1;  
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int flag = 0; 

    while (front < rear) {
        Node* current = queue[front++];
        if (current == NULL) {
            flag = 1;
        } else {
            if (flag == 1) {
                return 0;
            }

            queue[rear++] = current->left;
            queue[rear++] = current->right;
        }
    }

    return 1; 
}
void printInOrder(Node* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
    printf("\n");
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    printInOrder(root);
    if (isCompleteBinaryTree(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

