#include <iostream>
using namespace std;

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[minIndex], arr[i]);
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
    selectionSort(arr, n);
    print(arr, n);
}