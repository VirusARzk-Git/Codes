#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(int *arr, int n)
{
    vector<int> lis(n, 1);
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + 1);
    return *max_element(lis.begin(), lis.end());
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