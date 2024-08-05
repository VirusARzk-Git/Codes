#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n0;
        cin >> n0;
        int count[n0] = {0};
        int variable;
        int lol = 0;
        for (int i = 0; i < n0; i++)
        {
            cin >> variable;
            count[variable - 1]++;
            if (count[variable - 1] == 1)
                lol++;
        }
        if (lol % 2 == 0)
        {
            cout << "YES\n";
            continue;
        }
        if (n0 - lol > 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}