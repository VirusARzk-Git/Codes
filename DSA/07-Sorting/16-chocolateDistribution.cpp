#include <iostream>
#include <algorithm>
using namespace std;

// m  no of children
// Each child must get exactly one packet
// Min difference between the two children who get the min and max

int chocolate(int *arr, int n, int m)
{
    if (m > n)
        return -1;
    sort(arr, arr + n);
    int ans = arr[m - 1] - arr[0];
    for (int i = m; i < n; i++)
        ans = min(ans, arr[i] - arr[i - m + 1]);
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << chocolate(arr, n, m);
}