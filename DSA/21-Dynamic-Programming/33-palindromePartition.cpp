#include <iostream>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    if (i >= j)
        return true;
    return (s[i] == s[j] && isPalindrome(s,i + 1, j - 1));
}

int palPart(string s, int i, int j)
{
    if (isPalindrome(s, i, j))
        return 0;
    int res = INT_MAX;
    for (int k = i; k < j; k++)
        res = min(res, 1 + palPart(s, i, k) + palPart(s, k+1, j));
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << palPart(s, 0, s.size() - 1);
}