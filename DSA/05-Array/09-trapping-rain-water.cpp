#include <iostream>
using namespace std;

int trappingRainwater(int *arr, int n)
{
    int  ans = 0, lmax[n] = {arr[0]}, rmax[n] = {0};
    rmax[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
        lmax[i] = max(arr[i], lmax[i - 1]), rmax[n - i - 1] = max(arr[n - i - 1], rmax[n - i]);
    for (int i = 0; i < n; i++)
        ans += min(lmax[i], rmax[i]) - arr[i];
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << trappingRainwater(arr, n) << endl;
    }
}