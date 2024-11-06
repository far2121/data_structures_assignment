#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100 // Maximum size of the stack

int stack[MAX]; // Array to store stack elements
int top = -1;   // Initialize top to -1 to indicate the stack is empty

// Function to push an element onto the stack
void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack overflow.\n");
        exit(EXIT_FAILURE); // Exit if overflow occurs
    }
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow.\n");
        exit(EXIT_FAILURE); // Exit if underflow occurs
    }
    return stack[top--];
}

// Function to evaluate the suffix expression
int evaluateSuffix(const char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        // If the character is a digit, push it onto the stack
        if (isdigit(expression[i])) {
            push(expression[i] - '0'); // Convert char to int
        } else {
            // The character is an operator, pop two operands
            int operand2 = pop();
            int operand1 = pop();
            int result;

            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(EXIT_FAILURE); // Exit for invalid operator
            }
            // Push the result back onto the stack
            push(result);
        }
    }
    // The final result will be the only value left on the stack
    return pop();
}

int main() {
    const char* expression = "53+82-*"; // Example suffix expression

    // Evaluate the expression and display the result
    int result = evaluateSuffix(expression);
    printf("The result of the suffix expression \"%s\" is: %d\n", expression, result);

    return 0;
}