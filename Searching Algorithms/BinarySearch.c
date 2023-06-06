#include <stdio.h>
#include <conio.h>

int binarySearch(int arr[], int n, int val)
{
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right)
    {
        // Calculate the middle index using the formula (left + right) / 2
        mid = (right + left) / 2;

        if (arr[mid] == val)
        {
            // Element found at the middle index
            return mid + 1;
        }

        if (arr[mid] > val)
        {
            // Target value is smaller, search in the left half of the remaining array
            right = mid - 1;
        }
        else if (arr[mid] < val)
        {
            // Target value is larger, search in the right half of the remaining array
            left = mid + 1;
        }
    }

    // Target value not found in the array
    return -1;
}

int recursiveBinarySearch(int arr[], int left, int right, int val)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == val)
            // Element found at the middle index
            return mid + 1;

        else if (arr[mid] < val)
            // Target value is larger, search in the right half of the remaining array
            return recursiveBinarySearch(arr, mid + 1, right, val);

        else
            // Target value is smaller, search in the left half of the remaining array
            return recursiveBinarySearch(arr, left, mid - 1, val);
    }

    // Target value not found in the array
    return -1;
}

int main()
{
    int arr[] = {0, 1, 2, 5, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = 6;

    // int ans = binarySearch(arr, n, val);
    int ans = recursiveBinarySearch(arr, 0, n - 1, val);
    printf("Element found at index: %d", ans);

    return 0;
}
