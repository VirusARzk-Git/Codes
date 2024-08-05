#include <iostream>
using namespace std;

int sum(int *arr, int i, int n)
{
    int sum = 0;
    for (; i <= n; i++)
        sum += arr[i];
    return sum;
}

int minPages(int *arr, int n, int k)
{
    if (k == 1)
        return sum(arr, 0, n - 1);
    if (n == 1)
        return arr[0];
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
        res = min(res, max(minPages(arr, i, k - 1), sum(arr, i, n - 1)));
    return res;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << minPages(arr, n, k) << endl;
}