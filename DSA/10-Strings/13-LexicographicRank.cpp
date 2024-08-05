#include <iostream>
using namespace std;
#define CHAR 256

int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n - 1);
}

int lexicographicRank(string s)
{
    int rank = 1;
    int n = s.length();
    int mul = fact(n);
    int i;

    int count[CHAR] = {0};

    for (i = 0; i < n; i++)
        count[s[i]]++;

    for (i = 1; i < CHAR; i++)
        count[i] += count[i - 1];

    for (i = 0; i < n - 1; i++)
    {
        mul = mul / (n - i);
        rank = rank + count[s[i] - 1] * mul;
        for (int j = s[i]; j < CHAR; j++)
            count[j]--;
    }

    return rank;
}

int main()
{
    string s;
    cin >> s;
    cout << lexicographicRank(s);
}