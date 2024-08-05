#include <bits/stdc++.h>

using namespace std;
#define LLL long long

void precompute(const string &s, vector<vector<bool>> &isPal)
{
    LLL n = s.size();
    for (LLL i = 0; i < n; ++i)
        isPal[i][i] = true;
    for (LLL len = 2; len <= n; ++len)
        for (LLL i = 0; i <= n - len; ++i)
        {
            LLL j = i + len - 1;
            if (s[i] == s[j])
                if (len == 2)
                    isPal[i][j] = true;
                else
                    isPal[i][j] = isPal[i + 1][j - 1];
        }
}

LLL countGoodTriplets(const string &s)
{
    LLL n = s.size();
    vector<vector<bool>> isPal(n, vector<bool>(n, false));
    precompute(s, isPal);

    vector<LLL> left(n, 0), right(n, 0);

    for (LLL i = 0; i < n; ++i)
    {
        for (LLL j = 0; j <= i; ++j)
            if (isPal[j][i])
                left[i]++;
        if (i > 0)
            left[i] += left[i - 1];
    }

    for (LLL i = n - 1; i >= 0; --i)
    {
        for (LLL j = i; j < n; ++j)
            if (isPal[i][j])
                right[i]++;
        if (i < n - 1)
            right[i] += right[i + 1];
    }

    LLL ans = 0;

    for (LLL i = 1; i < n - 1; ++i)
        for (LLL j = i; j < n - 1; ++j)
            if (isPal[i][j])
                ans += left[i - 1] * right[j + 1];

    return ans;
}

int main()
{
    LLL t;
    cin >> t;
    while (t--)
    {
        LLL n;
        cin >> n;
        string s;
        cin >> s;
        cout << countGoodTriplets(s) << endl;
    }
    return 0;
}