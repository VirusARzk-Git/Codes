#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

void code_iske_andar_hai()
{
    int tkt, ppl;
    cin >> tkt >> ppl;
    vector<int> tp(tkt), pp(ppl);
    for (int i = 0; i < tkt; i++)
        cin >> tp[i];
    for (int i = 0; i < ppl; i++)
        cin >> pp[i];
    multiset<int> s(all(tp));

    for (int i = 0; i < ppl; i++)
    {
        auto it = s.upper_bound(pp[i]);
        if (it == s.begin())
            cout << -1 << endl;
        else
        {
            cout << *(--it) << endl;
            s.erase(it);
        }
    }
}

signed main()
{
    // noTLE;
    code_iske_andar_hai();
    return 0;
}