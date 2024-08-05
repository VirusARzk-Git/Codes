#include <iostream>
using namespace std;

int searchInSortedRotatedArray(int *arr, int n, int val)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == val)
            return mid;
        if (arr[low] <= arr[mid]) //  Left-Half Sorted
        {
            if (val >= arr[low] and val < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else // Right-Half Sorted
        {
            if (val > arr[mid] and val <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, val;
    cin >> n >> val;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << searchInSortedRotatedArray(arr, n, val);
}