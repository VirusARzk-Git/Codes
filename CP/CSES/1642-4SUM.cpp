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
    for (int j = 0; j < n - 3; j++)
        for (int i = j + 1; i < n - 2; i++)
        {
            int start = i + 1, end = n - 1;
            while (start < end)
            {
                int v = arr[end].first + arr[start].first + arr[i].first + arr[j].first;
                if (v < x)
                    start++;
                else if (v > x)
                    end--;
                else
                {
                    cout << arr[j].second << ' ' << arr[i].second << ' ' << arr[start].second << ' ' << arr[end].second;
                    return 0;
                }
            }
        }
    cout << "IMPOSSIBLE";
    return 0;
}