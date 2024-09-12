#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int i = 0)
{
    if (i == n)
        return;
    int j = i;
    while (j > 0 && arr[j] < arr[j - 1])
    {
        swap(arr[j], arr[j - 1]);
        j--;
    }
    insertionSort(arr, n, i + 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    insertionSort(arr, n);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}