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

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int j = low - 1;

    for (int i = low; i < high; i++)
    {
        if (arr[i] < pivot)
        {
            j++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j + 1], &arr[high]);
    return (j + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {1, 2, 5, 3, 6, 4, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Elements before Sorting: ");
    printArray(arr, n);

    // Call the quick sort function to sort the array
    quickSort(arr, 0, n - 1);

    printf("\nElements after Sorting: ");
    printArray(arr, n);

    return 0;
}
