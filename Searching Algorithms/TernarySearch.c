#include <stdio.h>
#include <conio.h>

// Function to perform ternary search
int ternarySearch(int arr[], int val, int n)
{
    int right = n - 1;
    int left = 0;
    int mid1, mid2;

    while (left <= right)
    {
        // Calculate the two midpoints
        mid1 = left + (right - left) / 3;
        mid2 = right - (right - left) / 3;

        // Check if the target value is found at mid1
        if (arr[mid1] == val)
        {
            return mid1; // Target value found at mid1, return its index
        }
        // Check if the target value is found at mid2
        else if (arr[mid2] == val)
        {
            return mid2; // Target value found at mid2, return its index
        }
        // Adjust the search space based on comparisons
        else if (val < arr[mid1])
        {
            right = mid1 - 1; // Target value is in the left portion of the array
        }
        else if (val > arr[mid1] && val < arr[mid2])
        {
            left = mid1 + 1; // Target value is in the middle portion of the array
            right = mid2 - 1;
        }
        else
        {
            left = mid2 + 1; // Target value is in the right portion of the array
        }
    }

    return -1; // Target value not found in the array
}

int recursiveTernarySearch(int arr[], int val, int low, int high)
{
    if (high >= low)
    {
        int mid1 = low + (high - low) / 3;  // Calculate the first mid-point
        int mid2 = high - (high - low) / 3; // Calculate the second mid-point

        if (arr[mid1] == val)
            return mid1; // Target value found at mid1, return its index
        else if (arr[mid2] == val)
            return mid2; // Target value found at mid2, return its index
        else if (val < arr[mid1])
            return recursiveTernarySearch(arr, val, low, mid1 - 1); // Target value is in the first third
        else if (val > arr[mid1] && val < arr[mid2])
            return recursiveTernarySearch(arr, val, mid1 + 1, mid2 - 1); // Target value is in the second third
        else
            return recursiveTernarySearch(arr, val, mid2 + 1, high); // Target value is in the last third
    }
    return -1; // Target value is not found in the array
}

int main()
{
    int arr[] = {0, 1, 2, 5, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = 5;

    // int ans = ternarySearch(arr, val, n);
    int ans = recursiveTernarySearch(arr, val, 0, n);
    printf("Element found at index: %d", ans);

    return 0;
}
