#include <iostream>
using namespace std;

const int CHAR = 256;
int nonRepeating(string s)
{
    int fI[CHAR];
    fill(fI, fI + CHAR, -1);
    for (int i = 0; i < s.length(); i++)
        if (fI[s[i]] == -1)
            fI[s[i]] = i;
        else
            fI[s[i]] = -2;
    int res = INT_MAX;
    for (int i = 0; i < CHAR; i++)
        if (fI[i] >= 0)
            res = min(res, fI[i]);
    return (res == INT_MAX) ? -1 : res;
}

int main()
{
    string s;
    cin >> s;
    cout << nonRepeating(s);
}