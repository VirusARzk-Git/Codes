using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vs = vector<string>;

class Solution
{
    vs str;

    int f(int i, int m, int n, vvvi &memo)
    {
        if (i == 0 || (m == 0 && n == 0))
            return 0;
        if (memo[i][m][n] != -1)
            return memo[i][m][n];
        int c0 = 0, c1 = 0;
        for (char ch : str[i - 1])
            if (ch == '0')
                c0++;
        c1 = str[i - 1].size() - c0;
        int pick = 0, notPick = 0;
        if (c0 <= m && c1 <= n)
            pick = 1 + f(i - 1, m - c0, n - c1, memo);
        notPick = f(i - 1, m, n, memo);
        return memo[i][m][n] = max(pick, notPick);
    }

public:
    int findMaxForm(vs &strs_, int m, int n)
    {
        str = strs_;
        int k = str.size();
        vvvi memo(k + 1, vvi(m + 1, vi(n + 1, -1)));
        return f(k, m, n, memo);
    }
};