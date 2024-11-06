#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // 0! and 1! are 1
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;

    // Ask the user for the input number
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);

    // Check for negative input
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Print the factorial of the number
        printf("Factorial of %d is %llu\n", num, factorial(num));
    }

    return 0;
}