#include <bits/stdc++.h>
using namespace std;

string T, P;
int LP, LT;

bool match(int L, int R)
{
    for (int i = 0; i < LP; i++)
        if (T[L + i] != P[i])
            return false;
    return true;
}

signed main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        getline(cin, T);
        getline(cin, P);
        LP = P.size();
        LT = T.size();

        for (int L = 0, R = LP - 1; R < LT; R++, L++)
            if (match(L, R))
                cout << L << " ";
        cout << endl;
    }

    return 0;
}