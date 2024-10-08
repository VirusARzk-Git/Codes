#include <iostream>
using namespace std;

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j], j--;
        arr[j + 1] = key;
    }
}

void input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    input(arr, n);
    insertionSort(arr, n);
    print(arr, n);
}