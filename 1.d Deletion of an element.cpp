#include <stdio.h>

#define MAX 100

void deleteElement(int arr[], int *size, int position);

int main() 
{
    int arr[MAX] = {1, 2, 3, 4, 5};  // Example array
    int size = 5;  // Current size of the array
    int position;

    printf("Enter the position to delete (1 to %d): ", size);
    scanf("%d", &position);

    deleteElement(arr, &size, position);

    printf("Array after deletion: ");
    for (int i = 0; i < size; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void deleteElement(int arr[], int *size, int position) 
{
    if (position < 1 || position > *size) 
	{
        printf("Invalid position!\n");
        return;
    }

    for (int i = position - 1; i < *size - 1; i++) 
	{
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Element deleted successfully.\n");
}
