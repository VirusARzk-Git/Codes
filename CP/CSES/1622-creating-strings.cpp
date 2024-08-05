
// for i in range(len(a)):
// l[int(a[i])-97]+=1
// for i in range(26):
// m = m//factorial[l[i]];
// print(m)

#include <bits/stdc++.h>
using namespace std;

set<string> st;
void permute(string s, int i = 0)
{
    if (i == s.length() - 1)
    {
        st.insert(s);
        return;
    }
    for (int j = i; j < s.length(); j++)
    {
        swap(s[i], s[j]);
        permute(s, i + 1);
        swap(s[i], s[j]);
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    string a;
    cin >> a;
    int factorial[] = {1, 1, 2, 6, 24, 120, 720, 720 * 7, 720 * 7 * 8};
    int m = factorial[a.length()];
    int l[26] = {0};
    for (int i = 0; i < a.length(); i++)
        l[a[i] - 97] += 1;
    for (int i = 0; i < 26; i++)
        m = m / factorial[l[i]];
    cout << m<<endl;
    permute(a);
    for (auto i : st)
        cout << i << endl;
    return 0;
}