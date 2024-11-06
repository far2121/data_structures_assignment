#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary search tree (BST)
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data); // If the tree is empty, create a new node
    }

    if (data < root->data) {
        // Insert in the left subtree
        root->left = insert(root->left, data);
    } else {
        // Insert in the right subtree
        root->right = insert(root->right, data);
    }

    return root;
}

// Function for postorder traversal of the BST (for displaying the tree)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);  // Traverse the left subtree
        postorderTraversal(root->right); // Traverse the right subtree
        printf("%d ", root->data);       // Print the node's data (visit the node)
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert elements into the BST
    int elements[] = {8, 10, 3, 1, 6, 14, 7};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }

    // Display the BST in postorder tr