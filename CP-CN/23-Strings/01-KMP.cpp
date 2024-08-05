#include <iostream>
#include <vector>
using namespace std;

string s, pattern;
vector<int> lps;
int n, m;

void KMP()
{
    lps.resize(n, 0);
    int i = 1, j = 0;
    while (i < n)
    {
        if (pattern[i] == pattern[j])
            lps[i++] = ++j;
        else if (j == 0)
            i++;
        else
            j = lps[j - 1];
    }
    for (int i : lps)
        cout << i << ' ';
}

int main()
{
    cin >> s >> pattern;
    m = s.size();
    n = pattern.size();
    KMP();

    int i = 0, j = 0;
    while (i < m)
    {
        if (s[i] == pattern[j])
            i++, j++;
        else if (j == 0)
            i++;
        else
            j = lps[j - 1];
        if (j == n)
        {
            cout << i - n << endl;
            j = lps[j - 1];
        }
    }
}