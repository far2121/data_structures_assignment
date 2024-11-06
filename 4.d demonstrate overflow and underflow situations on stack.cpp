#include <stdio.h>
#define MAX 5 // Define a small maximum size for easy demonstration of overflow and underflow

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
    // Demonstrate overflow condition
    printf("Demonstrating stack overflow:\n");
    for (int i = 1; i <= MAX + 2; i++) {
        push(i); // Push more elements than the stack can hold to trigger overflow
    }

    // Display current stack
    display();

    // Demonstrate underflow condition
    printf("\nDemonstrating stack underflow:\n");
    for (int i = 0; i <= MAX + 1; i++) {
        pop(); // Pop more elements than are in the stack to trigger underflow
    }

    return 0;
}