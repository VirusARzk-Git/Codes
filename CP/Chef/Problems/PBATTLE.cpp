/*
Aditya Raj
*/
// #include <string>
#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int
#define fast_tc       \
    int virusarzk;    \
    cin >> virusarzk; \
    while (virusarzk--)

int main()
{
    fast_tc
    {
        int n;
        cin >> n;
        vector<ll> a, b;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            b.push_back(x);
        }
        vector<pair<ll, ll>> c;
        for (int i = 0; i < n; i++)
            c.push_back(make_pair(a[i], b[i]));
        sort(c.rbegin(), c.rend());
        int cnt = 1, max = c[0].second;
        for (int i = 1; i < n; i++)
            if (c[i].second > max)
            {
                cnt++;
                max = c[i].second;
            }
        cout << cnt << endl;
    }
    return 0;
}