#include <iostream>
#include <set>
using namespace std;

void subSeq(string s, string t, int i, set<string> &st)
{
    if (i == s.size())
    {
        st.insert(t);
        return;
    }
    subSeq(s, t, i + 1, st);
    subSeq(s, t + s[i], i + 1, st);
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    set<string> st;
    subSeq(s, "", 0, st);
    for (auto i : st)
        cout << i << endl;
}