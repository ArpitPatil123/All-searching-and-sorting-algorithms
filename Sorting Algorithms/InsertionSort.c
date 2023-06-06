#include <stdio.h>

// Function to print the elements of an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Insertion sort implementation
void insertionSort(int arr[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        // Store the current element in a temporary variable
        int temp = arr[i];
        int j = i - 1;

        while (arr[j] > temp)
        {
            // If the element is greater than the current element,
            // move it one position ahead
            arr[j + 1] = arr[j];
            j--;
        }
        // Find the correct position to insert the current element
        // for (j = i - 1; j >= 0; j--)
        // {
        //     // If the element is smaller or equal to the current element,
        //     // break out of the loop as we have found the correct position
        //     if (arr[j] < temp)
        //         break;

        // }

        // Insert the current element at its correct position
        arr[j + 1] = temp;
    }
}

int main()
{
    int arr[] = {3, 1, 2, 5, 3, 6, 4, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Elements before Sorting: ");
    printArray(arr, n);

    // Call insertion sort function to sort the array
    insertionSort(arr, n);

    printf("\nElements after Sorting: ");
    printArray(arr, n);

    return 0;
}
