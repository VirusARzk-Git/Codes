using vi = vector<int>;
using vvi = vector<vi>;

class Solution
{
    vi a, b;
    int n, m;
    vvi memo;
    int f(int i, int j, int &ans)
    {
        if (i == 0 || j == 0)
            return 0;
        if (memo[i][j] != -1)
            return memo[i][j];
        if (a[i - 1] == b[j - 1])
        {
            int x = 1 + f(i - 1, j - 1, ans);
            ans = max(ans, x);
            f(i - 1, j, ans);
            f(i, j - 1, ans);
            return memo[i][j] = x;
        }
        f(i - 1, j, ans);
        f(i, j - 1, ans);
        return memo[i][j] = 0;
    }

public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        a = nums1;
        b = nums2;
        n = a.size();
        m = b.size();
        memo = vvi(n + 1, vi(m + 1, -1));
        int ans = 0;
        f(n, m, ans);
        return ans;
    }
};

// tabulation

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};