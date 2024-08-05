// Maximum value of arr[j]-arr[i] such that j>i

#include <iostream>
using namespace std;

int maxDiff(int *arr, int n)
{
    int minn = arr[0];
    int ans = arr[1] - arr[0];
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, arr[i] - minn);
        minn = min(minn, arr[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxDiff(arr, n) << endl;
}