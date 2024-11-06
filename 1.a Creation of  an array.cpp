#include <stdio.h>

#define MAX 100

void createArray(int arr[], int *size);

int main() 
{
    int arr[MAX];
    int size = 0;

    createArray(arr, &size);

    printf("Array created successfully with %d elements.\n", size);

    return 0;
}

void createArray(int arr[], int *size) 
{
    printf("Enter the number of elements: ");
    scanf("%d", size);

    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) 
	{
        scanf("%d", &arr[i]);
    }
}
