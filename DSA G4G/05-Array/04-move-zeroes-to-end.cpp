#include <bits/stdc++.h>
using namespace std;

void moveZeroesToEnd(int *arr, int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            swap(arr[i], arr[c++]);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    moveZeroesToEnd(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}