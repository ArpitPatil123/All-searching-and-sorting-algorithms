#include <stdio.h>

// Function to print the elements of an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Merge function to merge two sorted subarrays into a single sorted array
void merge(int arr[], int low, int high, int mid)
{
    // Create a temporary array to store the merged subarrays
    int temp[8];
    int i = low;     // Starting index of the left subarray
    int j = mid + 1; // Starting index of the right subarray
    int k = low;     // Starting index of the merged subarray

    // Merge the subarrays by comparing the elements
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++]; // Place the smaller element in the merged array
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    // Copy the remaining elements of the left subarray, if any
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of the right subarray, if any
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    // Copy the merged array back to the original array
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

// Merge sort function to recursively divide the array into subarrays and merge them
void mergeSort(int arr[], int low, int high)
{
    // Base case: If the array contains only one element, it is already sorted
    if (low < high)
    {
        int mid = (high + low) / 2; // Calculate the midpoint to divide the array into subarrays

        // Recursively divide the array into two halves and sort them
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted subarrays
        merge(arr, low, high, mid);
    }
}

int main()
{
    int arr[] = {1, 2, 5, 3, 6, 4, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Elements before Sorting: ");
    printArray(arr, n);

    // Call the merge sort function to sort the array
    mergeSort(arr, 0, n - 1);

    printf("\nElements after Sorting: ");
    printArray(arr, n);

    return 0;
}
