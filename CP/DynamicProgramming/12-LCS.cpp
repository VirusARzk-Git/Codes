// https://leetcode.com/problems/longest-common-subsequence/

using vi = vector<int>;
using vvi = vector<vi>;

class Solution
{
    string a, b;
    int n, m;
    vvi memo;
    int f(int i, int j)
    {
        if (i == 0 || j == 0)
            return 0;
        if (memo[i][j] != -1)
            return memo[i][j];
        if (a[i - 1] == b[j - 1])
            return memo[i][j] = 1 + f(i - 1, j - 1);
        return memo[i][j] = max(f(i - 1, j), f(i, j - 1));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        a = text1;
        b = text2;
        n = a.size();
        m = b.size();
        memo.resize(n + 1, vi(m + 1, -1));
        return f(n, m);
    }
};

// Tabulation

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};