#include <stdio.h>

// Function to print the elements of an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Function to swap two elements in an array
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Selection sort implementation
void selectionSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        // Find the minimum element in the remaining unsorted array
        int min = i;

        // Compare the current element with the remaining elements
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        // Swap the minimum element with the current element
        swap(&arr[i], &arr[min]);
    }
}

int main()
{
    int arr[] = {1, 2, 5, 3, 6, 4, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Elements before Sorting: ");
    printArray(arr, n);

    // Call selection sort function to sort the array
    selectionSort(arr, n);

    printf("\nElements after Sorting: ");
    printArray(arr, n);

    return 0;
}
