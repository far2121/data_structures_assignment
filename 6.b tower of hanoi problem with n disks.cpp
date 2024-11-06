#include <stdio.h>

// Function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", source, destination);
        return;
    }
    // Move top n-1 disks from source to auxiliary peg
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Move the nth disk from source to destination peg
    printf("Move disk %d from peg %c to peg %c\n", n, source, destination);
    
    // Move the n-1 disks from auxiliary to destination peg
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n; // Number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    // Solve the Tower of Hanoi problem
    printf("The moves involved are:\n");
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B, C are the names of the pegs

    return 0;
}