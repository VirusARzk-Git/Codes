using vi = vector<int>;
using vvi = vector<vi>;

vvi longestCommonSubsequence(string text1, string text2)
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
	return dp;
}

string findLCS(int n, int m, string &s1, string &s2)
{
	vvi dp = longestCommonSubsequence(s1, s2);
	string ans = "";
	int i = n, j = m;
	while (i > 0 && j > 0)
	{
		if (dp[i][j] == dp[i - 1][j])
			i--;
		else if (dp[i][j] == dp[i][j - 1])
			j--;
		else
		{
			ans += s1[i - 1];
			i--;
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}