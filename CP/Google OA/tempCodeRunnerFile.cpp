// Palidromic triplets

#include <bits/stdc++.h>
using namespace std;
#define int long long

void precompute(const string &s, vector<vector<bool>> &isPal)
{
    int n = s.size();
    for (int i = 0; i < n; ++i)
        isPal[i][i] = true;
    for (int len = 2; len <= n; ++len)
        for (int i = 0; i <= n - len; ++i)
        {
            int j = i + len - 1;
            if (s[i] == s[j])
            {
                if (len == 2)
                    isPal[i][j] = true;
                else
                    isPal[i][j] = isPal[i + 1][j - 1];
            }
        }
}

int countGoodTriplets(const string &s)
{
    int n = s.size();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    precompute(s, isPal);

    vector<int> left(n, 0), right(n, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
            if (isPal[j][i])
                left[i]++;
        if (i > 0)
            left[i] += left[i - 1];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = i; j < n; ++j)
            if (isPal[i][j])
                right[i]++;
        if (i < n - 1)
            right[i] += right[i + 1];
    }

    int ans = 0;

    for (int i = 1; i < n - 1; ++i)
        for (int j = i; j < n - 1; ++j)
            if (isPal[i][j])
                ans += left[i - 1] * right[j + 1];

    return ans;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << countGoodTriplets(s) << endl;
    }
    return 0;
}