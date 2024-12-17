using vi = vector<int>;
using vvi = vector<vi>;

int f(int n1, int n2, string &s1, string &s2, vvi &memo)
{
    if (n1 == 0)
        return n2;
    if (n2 == 0)
        return n1;
    if (memo[n1][n2] != -1)
        return memo[n1][n2];
    if (s1[n1 - 1] == s2[n2 - 1])
        return memo[n1][n2] = f(n1 - 1, n2 - 1, s1, s2, memo);
    int insert = 1 + f(n1, n2 - 1, s1, s2, memo);
    // int edit = 1 + f(n1 - 1, n2 - 1, s1, s2, memo);
    int remove = 1 + f(n1 - 1, n2, s1, s2, memo);
    return memo[n1][n2] = min(insert, remove);
}

int canYouMake(string &s1, string &s2)
{
    int n1 = s1.size(), n2 = s2.size();
    vvi memo(n1 + 1, vi(n2 + 1, -1));
    return f(n1, n2, s1, s2, memo);
}

// tabulation
int canYouMake(string &s1, string &s2)
{
    int n1 = s1.size(), n2 = s2.size();
    vvi dp(n1 + 1, vi(n2 + 1, 0));
    for (int i = 0; i <= n1; i++)
        for (int j = 0; j <= n2; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        }
    return dp[n1][n2];
}