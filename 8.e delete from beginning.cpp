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

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    // Inserting at the beginning
    if (position == 0) {
        newNode->next = *head; // Point new node to the current head
        *head = newNode; // Update head to the new node
        printf("Inserted %d at position %d (beginning of the list).\n", data, position);
        return;
    }

    // Traverse to the position before the desired location
    struct Node* temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Position %d is out of bounds. Insertion failed.\n", position);
            return; // Position is out of bounds
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of bounds. Insertion failed.\n", position);
        return; // Position is out of bounds
    }

    newNode->next = temp->next; // Link new node to the next node
    temp->next = newNode; // Link previous node to the new node
    printf("Inserted %d at position %d.\n", data, position);
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head; // Store the current head
    *head = (*head)->next; // Update head to the next node
    free(temp); // Free the old head
    printf("Deleted the node from the beginning of the list.\n");
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

    // Delete a node from the beginning
    deleteFromBeginning(&head);
    displayList(head);

    // Delete another node from the beginning
    deleteFromBeginning(&head);
    displayList(head);

    // Delete remaining nodes
    deleteFromBeginning(&head);
    deleteFromBeginning(&head);
    
    // Attempt to delete from an empty list
    deleteFromBeginning(&head);
    
    // Clean up memory (freeing nodes)
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}