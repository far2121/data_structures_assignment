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

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack underflow. The stack is empty.\n");
    } else {
        int poppedElement = stack[top];
        top--;
        printf("%d has been popped from the stack.\n", poppedElement);
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
        printf("2. Pop an element from the stack\n");
        printf("3. Display the stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}