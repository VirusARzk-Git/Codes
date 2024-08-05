#include <iostream>
using namespace std;

void partition(int *arr, int low, int high, int p)
{
    int temp[high - low + 1] = {0}, idx = 0;
    for (int i = low; i <= high; i++)
        if (arr[i] < arr[p])
            temp[idx++] = arr[i];
    temp[idx++] = arr[p];
    for (int i = low; i <= high; i++)
        if (arr[i] > arr[p])
            temp[idx++] = arr[i];
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

int main()
{
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    partition(arr, 0, n - 1, d);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}