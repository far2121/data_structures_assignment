#include <stdio.h>

// Function to display a sparse matrix in a compact form (row, column, value)
void displaySparseMatrix(int matrix[][3], int nonZeroCount) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d\t%d\t%d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}

int main() {
    int rows, cols;

    // Ask the user for the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    // Take inputs for the matrix
    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element at (%d, %d): ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Count non-zero elements to create a compact representation
    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    // Create a compact matrix to hold non-zero elements
    int sparseMatrix[nonZeroCount][3];
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[index][0] = i;
                sparseMatrix[index][1] = j;
                sparseMatrix[index][2] = matrix[i][j];
                index++;
            }
        }
    }

    // Display the sparse matrix
    printf("\nSparse Matrix Representation:\n");
    displaySparseMatrix(sparseMatrix, nonZeroCount);

    return 0;
}