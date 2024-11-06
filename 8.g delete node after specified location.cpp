#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head; // Point new node to the current head
    *head = newNode; // Update head to the new node
    printf("Inserted %d at the beginning of the list.\n", data);
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode; // If list is empty, new node becomes the head
        printf("Inserted %d at the end of the list.\n", data);
        return;
    }

    struct Node* temp = *head; // Start at the head
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the last node
    }
    temp->next = newNode; // Link the last node to the new node
    printf("Inserted %d at the end of the list.\n", data);
}

// Function to delete a node after a specified location
void deleteAfterPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;

    // Traverse to the specified position
    for (int i = 0; i < position; i++) {
        if (temp == NULL) {
            printf("Position %d is out of bounds. Deletion failed.\n", position);
            return; // Position is out of bounds
        }
        temp = temp->next; // Move to the next node
    }

    // If there is no node after the specified position
    if (temp == NULL || temp->next == NULL) {
        printf("There is no node to delete after position %d.\n", position);
        return; // No node to delete after the specified position
    }

    struct Node* nodeToDelete = temp->next; // Node to be deleted
    temp->next = nodeToDelete->next; // Bypass the node to be deleted
    free(nodeToDelete); // Free the memory of the deleted node
    printf("Deleted the node after position %d.\n", position);
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the linked list operations
int main() {
    struct Node* head = NULL; // Initialize the head of the list

    // Insert nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    // Display the list
    displayList(head);

    // Insert nodes at the end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    // Display the list again
    displayList(head);

    // Delete a node after a specified position
    deleteAfterPosition(&head, 1); // Delete node after position 1
    displayList(head);

    // Try to delete after the last node
    deleteAfterPosition(&head, 2); // Delete node after position 2
    displayList(head);

    // Attempt to delete after an invalid position
    deleteAfterPosition(&head, 5); // Attempting deletion after an out of bounds position
    displayList(head);

    // Clean up memory (freeing nodes)
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}