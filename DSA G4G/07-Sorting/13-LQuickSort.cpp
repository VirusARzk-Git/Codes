#include <iostream>
using namespace std;

int lomutoPartition(int *arr, int low, int high, int p = 0)
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

void qSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int p = lomutoPartition(arr, low, high);
        qSort(arr, low, p - 1);
        qSort(arr, p + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    qSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}