#include <iostream>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    if (i >= j)
        return true;
    return (s[i] == s[j] && isPalindrome(s, i + 1, j - 1));
}

int palPart(string s)
{
    if (isPalindrome(s, 0, s.length() - 1))
        return 0;
    int n = s.length();
    int dp[n][n] = {0};
    for (int gap = 1; gap < n; gap++)
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap;
            if (isPalindrome(s, i, j))
                dp[i][j] = 0;
            else
            {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
            }
        }

    return dp[0][n - 1];
}

int main()
{
    string s;
    cin >> s;
    cout << palPart(s);
}