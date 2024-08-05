#include <bits/stdc++.h>
using namespace std;
#define int long long

void code()
{
    int m, s;
    cin >> m >> s;
    if (s == 0 && m == 1)
    {
        cout << "0 0\n";
        return;
    }
    if (s == 0 || s > 9 * m)
    {
        cout << "-1 -1\n";
        return;
    }
    string minn = "", maxx = "";
    int sum = s;
    for (int i = 0; i < m; i++)
    {
        int digit = min(9LL, sum);
        maxx += (char)(digit + '0');
        sum -= digit;
    }
    sum = s - 1;
    for (int i = 0; i < m; i++)
    {
        int digit = min(9LL, sum);
        minn += (char)(digit + '0');
        sum -= digit;
    }
    reverse(minn.begin(), minn.end());
    minn[0]++;
    cout << minn << ' ' << maxx << endl;
}

signed main()
{
    code();
    return 0;
}