#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first;
    for (int i = 0; i < n; i++)
        arr[i].second = i + 1;
    sort(arr.begin(), arr.end());
    int start = 0, end = n - 1;
    while (start < end)
    {
        int v = arr[end].first + arr[start].first;
        if (v < x)
            start++;
        else if (v > x)
            end--;
        else
        {
            cout << arr[start].second << ' ' << arr[end].second;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}