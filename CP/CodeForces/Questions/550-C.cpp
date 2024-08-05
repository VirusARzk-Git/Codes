#include <bits/stdc++.h>
using namespace std;

#define int long long
#define no cout << "NO\n"
void code()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' || s[i] == '8')
        {
            cout << "YES\n"
                 << s[i];
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int num = (s[i] - '0') * 10 + (s[j] - '0');
            if (num % 8 == 0)
            {
                cout << "YES\n"
                     << num;
                return;
            }
            // cout << num << endl;
            for (int k = j + 1; k < n; k++)
            {
                int m = num * 10 + (s[k] - '0');
                // cout << m << ' ' << k << endl;
                if (m % 8 == 0)
                {
                    cout << "YES\n"
                         << m;
                    return;
                }
            }
        }
    }
    no;
}

signed main()
{
    code();
    return 0;
}