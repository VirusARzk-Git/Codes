#include <iostream>
#include <algorithm>
using namespace std;

int edit_Dist(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int i = 0; i <= n; i++)
        dp[0][i] = i;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
    return dp[m][n];
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << edit_Dist(a, b);
}