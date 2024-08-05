#include <iostream>
using namespace std;

bool isPalindrome(string &str, int start, int end)
{
    if (start >= end)
        return true;
    return (str[start] == str[end] && isPalindrome(str, start + 1, end - 1));
}

string isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++)
    {
        if (S[i] != S[S.length() - i - 1])
            return false;
    }
    return true;
}

int scoreString(string str)
{
    int n = str.length();
    int score = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 3 < n)
        {
            if (isPalindrome(str, i, i + 3))
                score += 5;
        }
        if (i + 4 < n)
        {
            if (isPalindrome(str, i, i + 4))
                score += 10;
        }
    }
    return score;
}
int main()
{
    string s;
    cin >> s;
    if (isPalindrome(s, 0, s.length() - 1))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}
