#include <bits/stdc++.h>
using namespace std;

vector<int> z_function_trivial(string s)
{
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1; i < n; ++i)
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
    return z;
}

vector<int> z_function(string s)
{
    int n = s.length();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n and s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

signed main()
{
    string s;
    cin >> s;
    vector<int> z = z_function(s);
    for (int k : z)
        cout << k << ' ';
    return 0;
}