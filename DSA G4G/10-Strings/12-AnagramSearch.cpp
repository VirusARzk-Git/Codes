#include <iostream>
using namespace std;

#define CHAR 256

bool arrSame(int *a, int *b)
{
    for (int i = 0; i < CHAR; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

bool AnagramSearch(string txt, string pat)
{
    int CT[CHAR] = {0}, CP[CHAR] = {0};
    for (int i = 0; i < pat.length(); i++)
        CT[txt[i]]++, CP[pat[i]]++;
    for (int i = pat.length(); i < txt.length(); i++)
        if (arrSame(CT, CP))
            return true;
        else
            CT[txt[i]]++, CT[txt[i - pat.length()]]--;
    if (arrSame(CT, CP))
        return true;
    else
        return false;
}

int main()
{
    string txt, pat;
    getline(std::cin, txt);
    cin >> pat;
    cout << AnagramSearch(txt, pat);
}