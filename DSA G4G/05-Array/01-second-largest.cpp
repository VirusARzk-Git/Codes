#include <bits/stdc++.h>
using namespace std;

int getLargestElement(int *arr, int n)
{
    int max = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[max])
            max = i;
    return max;
}

int getSecondLargestElement(int *arr, int n)
{
    int largest = getLargestElement(arr, n);
    int res = -1;
    for (int i = 0; i < n; i++)
        if (arr[i] != arr[largest])
            if (res == -1 or arr[i] > arr[res])
                res = i;
    return res;
}

signed main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << arr[getSecondLargestElement(arr, n)];
    return 0;
}