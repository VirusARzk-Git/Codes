#include <iostream>
using namespace std;

int memo[100][100];

int LCS(string s1, string s2, int m, int n)
{
    if (memo[m][n] >= 0)
        return memo[m][n];
    if (m == 0 || n == 0)
        return memo[m][n] = 0;
    if (s1[m - 1] == s2[n - 1])
        return memo[m][n] = 1 + LCS(s1, s2, m - 1, n - 1);
    return memo[m][n] = max(LCS(s1, s2, m, n - 1), LCS(s1, s2, m - 1, n));
}

int main()
{
    string a, b;
    cin >> a >> b;
    for (int i = 0; i <= a.size(); i++)
        for (int j = 0; j <= b.size(); j++)
            memo[i][j] = -1;
    cout << LCS(a, b, a.length(), b.length());
}
