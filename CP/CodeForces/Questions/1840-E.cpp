
#include <bits/stdc++.h>
using namespace std;

void code_iske_andar_hai()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int n = s1.length();
    vector<string> v;
    v.push_back("VirusARzk");
    v.push_back(s1);
    v.push_back(s2);
    int t, q;
    cin >> t >> q;
    unordered_map<int, bool> m;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (v[1][i] != v[2][i])
            cnt++;
    for (int i = 0; i < q; i++)
    {
        if (m[i])
            cnt++;
        int qt;
        cin >> qt;
        if (qt == 3)
        {
            if (cnt == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else if (qt == 2)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            b--, d--;
            if (b != d)
            {
                if (v[1][b] != v[2][b])
                    cnt--;
                if (v[1][d] != v[2][d])
                    cnt--;
                swap(v[a][b], v[c][d]);
                if (v[1][b] != v[2][b])
                    cnt++;
                if (v[1][d] != v[2][d])
                    cnt++;
            }
            else
                swap(v[a][b], v[c][d]);
        }
        else if (qt == 1)
        {
            int idx;
            cin >> idx;
            idx--;
            if (v[1][idx] != v[2][idx])
                m[i + t] = true, cnt--;
        }
    }
}

signed main()
{
    int virus_arzk;
    cin >> virus_arzk;
    while (virus_arzk--)
        code_iske_andar_hai();
    return 0;
}