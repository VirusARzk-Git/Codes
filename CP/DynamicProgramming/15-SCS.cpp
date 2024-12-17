class Solution
{

    using vi = vector<int>;
    using vvi = vector<vi>;
    string findLCS(int n, int m, string &s, string &t)
    {
        vvi dp(n + 1, vi(m + 1, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (s[i] == t[j])
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        string ans = "";
        int i = n, j = m;
        while (i && j && dp[i][j])
        {
            if (dp[i][j] == dp[i - 1][j])
                i--;
            else if (dp[i][j] == dp[i][j - 1])
                j--;
            else if (dp[i][j] == dp[i - 1][j - 1] + 1)
            {
                ans = s[i - 1] + ans;
                i--;
                j--;
            }
        }
        return ans;
    }

public:
    string shortestCommonSupersequence(string a, string b)
    {
        string lcs = findLCS(a.size(), b.size(), a, b);
        int i = 0, j = 0, k = 0;
        string ans = "";
        while (k < lcs.length())
        {
            while (a[i] != lcs[k])
            {
                ans += a[i];
                i++;
            }
            while (b[j] != lcs[k])
            {
                ans += b[j];
                j++;
            }
            ans += lcs[k];
            i++;
            j++;
            k++;
        }
        while (i < a.length())
            ans += a[i++];
        while (j < b.length())
            ans += b[j++];
        return ans;
    }
};