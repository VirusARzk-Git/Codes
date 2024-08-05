// Longest Substring with Distinct Characters

#include <iostream>
using namespace std;

#define CHAR 256

int longestSubstring(string s)
{
    int n = s.length();
    int res = 0;

    int prev[CHAR];
    fill(prev, prev + CHAR, -1);

    int i = 0;
    for (int j = 0; j < n; j++)
    {
        i = max(i, prev[s[j]] + 1);
        int maxEnd = j - i + 1;
        res = max(res, maxEnd);
        prev[s[j]] = j;
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << longestSubstring(s);
}