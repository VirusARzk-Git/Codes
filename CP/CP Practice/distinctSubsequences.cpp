#include <iostream>
#include <map>
using namespace std;

// count distinct subsequences

int countSub(string s)
{
    int n = s.size();
    vector<int> dp(256, 0);

    int ans = 1;
    dp[s[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        char c = s[i];
        int curr = ans + 1;
        ans += curr - dp[c];
        dp[c] = curr;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << countSub(s) << endl;
    return 0;
}