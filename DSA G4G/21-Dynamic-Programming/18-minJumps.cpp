#include <iostream>
using namespace std;

int minJumps(int *arr, int n)
{
    if (n == 1)
        return 0;
    int res = INT_MAX;
    for (int i = 0; i < n - 1; i++)
        if (i + arr[i] >= n - 1)
        {
            int subRes = minJumps(arr, i + 1);
            if (subRes != INT_MAX)
                res = min(res, subRes + 1);
        }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minJumps(arr, n);
}