#include <iostream>
using namespace std;

void LongestProperPrefixSuffix(string s)
{
    int n = s.length();
    int len = 0;
    int lps[n] = {0};
    int i = 1;
    while (i < n)
        if (s[i] == s[len])
            lps[i++] = ++len;
        else if (len == 0)
            lps[i++] = 0;
        else
            len = lps[len - 1];
    for (int i = 0; i < n; i++)
        cout << lps[i] << " ";
}

int main()
{
    string s;
    cin >> s;
    LongestProperPrefixSuffix(s);
}