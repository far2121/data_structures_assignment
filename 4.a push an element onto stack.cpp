#include <stdio.h>
#define MAX 100 // Define the maximum size of the stack

int stack[MAX]; // Array to store stack elements
int top = -1; // Initialize top to -1 to indicate the stack is empty

// Function to push an element onto the stack
void push(int element) {
    if (top >= MAX - 1) {
        printf("Stack overflow. Unable to push %d onto the stack.\n", element);
    } else {
        top++;
        stack[top] = element;
        printf("%d has been pushed onto the stack.\n", element);
    }
}

// Function to display the stack elements
void display() {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("\n1. Push an element onto the stack\n");
        printf("2. Display the stack\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                display();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}