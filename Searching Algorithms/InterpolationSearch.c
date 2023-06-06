#include <stdio.h>
#include <conio.h>

int interpolationSearch(int arr[], int val, int n)
{
    int high = n - 1;
    int low = 0;

    while (low <= high && val <= arr[high] && val >= arr[low])
    {
        // Calculate the probe position using interpolation formula
        int probe = low + ((val - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        printf("Probe: %d\n", probe);

        if (arr[probe] == val)
        {
            // Element found at the probe position
            return probe;
        }
        else if (arr[probe] > val)
        {
            // Target value is smaller, search in the left half of the remaining array
            high = probe - 1;
        }
        else
        {
            // Target value is larger, search in the right half of the remaining array
            low = probe + 1;
        }
    }

    // Target value not found in the array
    return -1;
}

int recursiveInterpolationSearch(int arr[], int val, int low, int high)
{
    if (low <= high && val >= arr[low] && val <= arr[high])
    {
        // Calculate the probe position using interpolation formula
        int probe = low + ((val - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[probe] == val)
        {
            // Element found at the probe position
            return probe;
        }
        else if (val <= arr[probe])
        {
            // Target value is smaller or equal to the probe value,
            // so search in the left subarray
            return recursiveInterpolationSearch(arr, val, low, probe - 1);
        }
        else
        {
            // Target value is greater than the probe value,
            // so search in the right subarray
            return recursiveInterpolationSearch(arr, val, probe + 1, high);
        }
    }
    // Element not found in the array
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int val = 5;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the interpolationSearch function to search for the target value
    // int ans = interpolationSearch(arr, val, n);
    int ans = recursiveInterpolationSearch(arr, val, 0, n - 1);
    printf("Element found at index: %d", ans);

    return 0;
}
