#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100 // Define the maximum size of the stack

char stack[MAX]; // Array to store stack elements
int top = -1; // Initialize top to -1 to indicate the stack is empty

// Function to push an element onto the stack
void push(char ch) {
    if (top >= MAX - 1) {
        printf("Stack overflow.\n");
    } else {
        top++;
        stack[top] = ch;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack underflow.\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

// Function to check if a string is a palindrome using a stack
bool isPalindrome(char str[]) {
    int len = strlen(str);

    // Push all characters of the string onto the stack
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    // Check characters by popping from the stack and comparing with the original string
    for (int i = 0; i < len; i++) {
        if (str[i] != pop()) {
            return false; // Mismatch found, not a palindrome
        }
    }

    return true; // All characters matched, it's a palindrome
}

int main() {
    char str[MAX];

    // Ask the user for the input string
    printf("Enter a string to check if it's a palindrome: ");
    scanf("%s", str);

    // Check if the string is a palindrome
    if (isPalindrome(str)) {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else {
        printf("The string \"%s\" is not a palindrome.\n", str);
    }

    return 0;
}