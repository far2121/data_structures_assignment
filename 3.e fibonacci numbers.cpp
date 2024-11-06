#include <stdio.h>

// Function to print Fibonacci numbers up to n terms
void printFibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;

    printf("Fibonacci Series up to %d terms:\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

int main() {
    int n;

    // Ask the user for the number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Print Fibonacci series
    if (n > 0) {
        printFibonacci(n);
    } else {
        printf("Please enter a positive number.\n");
    }

    return 0;
}