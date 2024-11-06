#include <stdio.h>

void displayArray(int arr[], int size);

int main() 
{
    int arr[] = {1, 2, 3, 4, 5};  // Example array
    int size = 5;  // Size of the example array

    displayArray(arr, size);

    return 0;
}

void displayArray(int arr[], int size) 
{
    printf("Array elements: ");
    for (int i = 0; i < size; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
}
