#include <stdio.h>

#define MAX 100

void insertElement(int arr[], int *size, int element, int position);

int main() 
{
    int arr[MAX] = {1, 2, 3, 5};  // Example array with space for more elements
    int size = 4;  // Current size of the array
    int element, position;

    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert (1 to %d): ", size + 1);
    scanf("%d", &position);

    insertElement(arr, &size, element, position);

    printf("Array after insertion: ");
    for (int i = 0; i < size; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void insertElement(int arr[], int *size, int element, int position) 
{
    if (position < 1 || position > *size + 1) 
	{
        printf("Invalid position!\n");
        return;

    for (int i = *size; i >= position; i--) 
	{
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}
