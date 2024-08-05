#include <bits/stdc++.h>
using namespace std;

#define int long long

#define B begin()
#define E end()
#define I iterator
using pii = pair<int, int>;
using vi = vector<int>;
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define all(x) x.begin(), x.end()

void code()
{
    string s;
    cin >> s;
    set<int> ab, ba;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'A' && s[i + 1] == 'B')
            ab.insert(i);
        if (s[i] == 'B' && s[i + 1] == 'A')
            ba.insert(i);
    }
    if (ab.empty() || ba.empty())
    {
        no;
        return;
    }
    int a = *ab.begin(), b = *ba.rbegin(), c = *ba.begin(), d = *ab.rbegin();
    if (abs(a - b) > 1 || abs(c - d) > 1)
        yes;
    else
        no;
}

signed main()
{
    code();
    return 0;
}