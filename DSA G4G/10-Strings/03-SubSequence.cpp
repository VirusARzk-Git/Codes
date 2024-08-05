#include <iostream>
using namespace std;

bool isSubsequence(string s, string t) // Iterative
{
    int k = 0;
    for (int i = 0; i < s.length(); i++)
        if (t[k] == s[i])
            k++;
    return (k == t.length());
}

bool isSubsequence(string s, string t, int n, int m) // Recursive
{
    if (m == 0)
        return true;
    if (n == 0)
        return false;
    if (s[n - 1] == t[m - 1])
        return isSubsequence(s, t, n - 1, m - 1);
    else
        return isSubsequence(s, t, n - 1, m);
}

int main()
{
    string str, t;
    cin >> str >> t;
    if (isSubsequence(str, t))
        cout << "Yes";
    else
        cout << "No";
    cout << "\n";
    if (isSubsequence(str, t, str.length(), t.length()))
        cout << "Yes";
    else
        cout << "No";
}