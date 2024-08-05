#include <iostream>
using namespace std;
void function(int *arr, int n)
{
    int cnt = 1;
    int mx = 1;
    for (int i = 1; i < n; i++)
        if (arr[i] % 2 != arr[i - 1] % 2)
            cnt++, mx = max(mx, cnt);
        else
            cnt = 1;
    cout << mx;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    function(arr, n);
}