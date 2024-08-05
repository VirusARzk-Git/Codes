#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ceil(vector<int> tail, int l, int r, int x)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (tail[m] >= x)
            r = m;
        else
            l = m + 1;
    }
    return r;
}

int LIS(int *arr, int n)
{
    vector<int> lis(n, 1);
    vector<int> tail(1, arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > tail[tail.size() - 1])
            tail.push_back(arr[i]);
        else
            tail[ceil(tail, 0, tail.size() - 1, arr[i])] = arr[i];
    }
    return tail.size();
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << LIS(arr, n) << endl;
}