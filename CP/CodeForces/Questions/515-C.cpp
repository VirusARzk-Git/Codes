#include <bits/stdc++.h>
using namespace std;

void code()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int d[10] = {0};
    for (auto i : s)
        d[i - '0']++;
    d[3] += d[9] * 2 + d[6] + d[4];
    d[7] += d[9] + d[8];
    d[5] += d[6];
    d[2] += d[9] + d[8] * 3 + d[4] * 2;
    d[9] = d[8] = d[6] = d[4] = 0;
    for (int i = 7; i >= 2; i--)
        while (d[i]--)
            cout << i;
}

signed main()
{
    code();
    return 0;
}