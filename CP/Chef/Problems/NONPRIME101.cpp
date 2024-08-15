#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define vpii vector<pair<int, int>>
#define pb push_back

bool if_prime(int m)
{
    if (m < 2)
        return false;
    for (int i = 2; i * i <= m; i++)
        if (m % i == 0)
            return false;
    return true;
}

void solution()
{
    int m;
    cin >> m;
    int arr[m];
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    if (m == 2)
        if (!if_prime(arr[0] + arr[1]))
        {
            cout << "1 2\n";
            return;
        }
    vpii o, e;
    for (int i = 0; i < m; i++)
        if (arr[i] % 2)
            o.pb({arr[i], i + 1});
        else
            e.pb({arr[i], i + 1});
    sort(all(o));
    sort(all(e));
    if (o.size() > 1 && o.back().first != 1)
    {
        int x = o.back().second, y = o.front().second;
        cout << x << ' ' << y << endl;
    }
    else if (e.size() > 1)
    {
        int x = e.back().second, y = e.front().second;
        cout << x << ' ' << y << endl;
    }
    else
        cout << -1 << endl;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solution();
    return 0;
}