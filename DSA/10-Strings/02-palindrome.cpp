#include <iostream>
#include <algorithm>
using namespace std;

bool isPal(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return (rev == s);
}

bool isPalindrome(string s)
{
    int begin = 0, end = s.length() - 1;
    while (begin < end)
    {
        if (s[begin] != s[end])
            return false;
        begin++;
        end--;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    if (isPalindrome(s))
        cout << "Palindrome";
    else
        cout << "Not palindrome";
}