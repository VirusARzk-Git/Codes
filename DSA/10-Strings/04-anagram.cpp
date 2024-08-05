#include <iostream>
#include <algorithm>
using namespace std;
const int CHAR = 256;

bool isAnagram(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return (s1 == s2);
}

bool isAnagram2(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;

    int count[CHAR] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for (int i = 0; i < CHAR; i++)
        if (count[i])
            return false;

    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (isAnagram(s1, s2))
        cout << "Anagram";
    else
        cout << "Not anagram";
    return 0;
}