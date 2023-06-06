#include <stdio.h>
#include <conio.h>

int linearSearch(int arr[], int val, int n)
{
    int i = 0;
    while (n--)
    {
        if (arr[i++] == val)
        {
            return i;
        }
    }
    return -1;
}

int recursiveLinearSearch(int arr[], int val, int n)
{
    if (n >= 0)
    {
        if (arr[n] == val)
            return n + 1;

        else
            return recursiveLinearSearch(arr, val, n - 1);
    }
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