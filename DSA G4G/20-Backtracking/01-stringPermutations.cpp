#include <iostream>
using namespace std;

//  Given a string, print all those permutations which do not contain "AB" as a substring
bool isSafe(string s, int l, int i, int r)
{
    if (l != 0 && s[l - 1] == 'A' && s[i] == 'B')
        return false;
    if (r == l + 1 && s[i] == 'A' && s[l] == 'B' || r == l + 1 && l == i && s[r] == 'B' && s[l] == 'A')
        return false;
    return true;
}

void permute(string s, int l, int r)
{
    if (l == r)
    {
        cout << s << endl;
        return;
    }
    else
        for (int i = l; i <= r; i++)
            if (isSafe(s, l, i, r))
            {
                swap(s[l], s[i]);
                permute(s, l + 1, r);
                swap(s[l], s[i]);
            }
}

int main()
{
    string s = "ABC";
    permute(s, 0, s.size() - 1);
    return 0;
}