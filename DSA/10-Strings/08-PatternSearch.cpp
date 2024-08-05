#include <iostream>
using namespace std;
#define d 256

void patSearch_Naive(string &txt, string &pat)
{
    int m = pat.length();
    int n = txt.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (pat[j] != txt[i + j])
                break;
        if (j == m)
            cout << i << ' ';
    }
}

void RBSearch(string &txt, string &pat, int q = INT_MAX) // Rabin Karp Algo
{
    int M = pat.length();
    int N = txt.length();
    int i, j;

    int h = 1;
    for (i = 1; i < M; i++)
        h = (h * d) % q;

    int p = 0, t = 0;
    for (i = 0; i < M; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            for (j = 0; j < M; j++)
                if (txt[i + j] != pat[j])
                    break;

            if (j == M)
                cout << i << ' ';
        }

        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            if (t < 0)
                t = t + q;
        }
    }
}

int main()
{
    string txt, pat;
    getline(std::cin, txt);
    cin >> pat;
    RBSearch(txt, pat);
}