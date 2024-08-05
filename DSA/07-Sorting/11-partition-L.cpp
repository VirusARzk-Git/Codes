#include <iostream>
using namespace std;

// Lomuto Partition
// We always have to consider the last element of the array as the pivot element

// In order to perform it for any other index,
// we need to swap the element at that index with the last element of the array

int lPartition(int *arr, int low, int high, int p = 0)
{
    // swap(arr[p], arr[high]);
    int pivot = arr[high]; // Always Last
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
        if (arr[j] <= pivot)
            i++, swap(arr[j], arr[i]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << lPartition(arr, 0, n - 1);
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}