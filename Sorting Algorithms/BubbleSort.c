#include <stdio.h>
#include <stdbool.h>

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

// Bubble sort implementation
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;

    // Iterate through the array
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;

        // Compare adjacent elements and swap if necessary
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by the inner loop,
        // the array is already sorted, so break out of the loop
        if (swapped == false)
            break;
    }
    printf("%d", i);
}

int main()
{
    int arr[] = {1, 2, 5, 3, 6, 4, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Elements before Sorting: ");
    printArray(arr, n);

    // Call bubble sort function to sort the array
    bubbleSort(arr, n);

    printf("\nElements after Sorting: ");
    printArray(arr, n);

    return 0;
}
