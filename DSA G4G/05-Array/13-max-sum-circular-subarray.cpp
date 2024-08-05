#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

void function(vector<int> arr, int n)
{
    int sum = 0;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] < 0)
            c++;
    }

    if (c == n)
    {
        cout << *max_element(all(arr));
        return 0;
    }

    int minEnding = arr[0];
    int maxEnding = arr[0];
    int mn = arr[0];
    int mx = arr[0];

    for (int i = 1; i < n; i++)
    {
        minEnding = min(minEnding + arr[i], arr[i]);
        mn = min(mn, minEnding);
        maxEnding = max(maxEnding + arr[i], arr[i]);
        mx = max(mx, maxEnding);
        // cout << minEnding << ' ' << mn << ' ' << maxEnding << ' ' << mx << endl;
    }
    // cout << mn << ' ' << mx << endl;
    cout << max(sum - mn, mx);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    function(arr, n);
}