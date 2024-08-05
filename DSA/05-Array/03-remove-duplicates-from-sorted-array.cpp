#include <iostream>
using namespace std;

int removeDuplicates(int *arr, int n)
{
    int res = 1;
    for (int i = 1; i < n; i++)
        if (arr[i] != arr[i - 1])
            arr[res++] = arr[i];
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    n = removeDuplicates(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}