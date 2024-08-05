#include <bits/stdc++.h>
using namespace std;

void printPowerSet(string str)
{
    int n = str.length();
    int powSize = pow(2, n);
    for (int cntr = 0; cntr < powSize; cntr++)
    {
        for (int j = 0; j < n; j++)
            if ((cntr & (1 << j)) != 0)
                cout << str[j];
        cout << endl;
    }
}

signed main()
{
    string s;
    cin >> s;
    printPowerSet(s);
    return 0;
}