#include <stdio.h>
#include <conio.h>

int binarySearch(int arr[], int n, int val)
{
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right)
    {
        // mid = left + (right - left) / 2;
        mid = (right + left) / 2;
        if (arr[mid] == val)
        {
            return mid + 1;
        }
        if (arr[mid] > val)
        {
            right = mid - 1;
        }

        else if (arr[mid] < val)
        {
            left = mid + 1;
        }
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int left, int right, int val)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == val)
            return mid + 1;

        else if (arr[mid] < val)
            return recursiveBinarySearch(arr, mid + 1, right, val);

        else
            return recursiveBinarySearch(arr, left, mid - 1, val);
    }
    return -1;
}

int main()
{
    int arr[] = {0, 1, 2, 5, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val = 6;

    // int ans = binarySearch(arr, n, val);
    int ans = recursiveBinarySearch(arr, 0, n, val);
    printf("Element found at index: %d", ans);
    return 0;
}