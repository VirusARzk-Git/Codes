#include <iostream>
using namespace std;

void reverse(string &s, int low, int high)
{
    while (low <= high)
    {
        swap(s[low], s[high]);
        low++, high--;
    }
}

void reverseWords(string &s)
{
    int n = s.length();
    int start = 0;
    for (int end = 0; end < n; end++)
        if (s[end] == ' ')
        {
            reverse(s, start, end - 1);
            start = end + 1;
        }
    reverse(s, start, n - 1);
    reverse(s, 0, n - 1);
}

int main()
{
    string s;
    getline(cin, s);
    reverseWords(s);
    cout << s;
}