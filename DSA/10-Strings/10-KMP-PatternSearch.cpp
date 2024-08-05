#include <iostream>
using namespace std;

void fillLPS(string s, int *lps)
{
    int n = s.length();
    int len = 0;
    int i = 1;
    while (i < n)
        if (s[i] == s[len])
            lps[i++] = ++len;
        else if (len == 0)
            lps[i++] = 0;
        else
            len = lps[len - 1];
    // for (int i = 0; i < n; i++)
    //     cout << lps[i] << " ";
}

void KMP_Search(string txt, string pat)
{
    int N = txt.length();
    int M = pat.length();

    int lps[M] = {0};
    fillLPS(pat, lps);

    int i = 0, j = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
            i++, j++;
        if (j == M)
        {
            cout << i - j << ' ';
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

int main()
{
    string txt, pat;
    getline(std::cin, txt);
    cin >> pat;
    KMP_Search(txt, pat); 
}