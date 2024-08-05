// Knuth Morris Pratt Algorithm

#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s)
{
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

signed main()
{
    string s;
    cin >> s;
    vector<int> v = prefix_function(s);
    for (auto i : v)
        cout << i << ' ';
    return 0;
}