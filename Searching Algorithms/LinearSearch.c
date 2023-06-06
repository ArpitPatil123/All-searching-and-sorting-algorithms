#include <stdio.h>
#include <conio.h>

// Function to perform linear search
int linearSearch(int arr[], int val, int n)
{
    int i = 0;

    // Iterate through the array
    while (n--)
    {
        if (arr[i++] == val)
        {
            // Element found at index i
            return i;
        }
    }

    // Element not found in the array
    return -1;
}

// Recursive function to perform linear search
int recursiveLinearSearch(int arr[], int val, int n)
{
    if (n >= 0)
    {
        if (arr[n] == val)
            // Element found at index n
            return n + 1;

        else
            // Search in the remaining array in reverse order
            return recursiveLinearSearch(arr, val, n - 1);
    }

    // Element not found in the array
    return -1;
}

int main()
{
    int arr[] = {0, 1, 5, 7, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = 6;

    // int ans = linearSearch(arr, val, n);
    int ans = recursiveLinearSearch(arr, val, n);
    printf("Element found at position: %d", ans);

    return 0;
}
