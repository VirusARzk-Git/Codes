#include <bits/stdc++.h>
using namespace std;

vector<int> search(string pattern, string text)
{
    int ps = pattern.size(), ts = text.size();
    int p = 249, m = 100001;
    int p_hash = 0, t_hash = 0;
    int p_pow = 1;
    for (int i = 0; i < ps; i++)
    {
        p_hash = (p_hash * p + (pattern[i] - 'a' + 1)) % m;
        t_hash = (t_hash * p + (text[i] - 'a' + 1)) % m;
        if (i != ps - 1)
            p_pow = (p_pow * p) % m;
    }
    vector<int> res;
    for (int i = ps; i <= ts; i++)
    {
        if (p_hash == t_hash)
        {
            bool found = true;
            for (int j = 0; j < ps; j++)
            {
                if (text[i - ps + j] != pattern[j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
                res.push_back(i - ps + 1);
        }
        if (i < ts)
        {
            t_hash = (t_hash - ((text[i - ps] - 'a' + 1) * p_pow) % m + m) % m;
            t_hash = (t_hash * p) % m;
            t_hash = (t_hash + (text[i] - 'a' + 1)) % m;
        }
    }
    return res;
}

int main()
{
    string pattern = "abc";
    string text = "abcabc";
    vector<int> res = search(pattern, text);
    for (int i : res)
        cout << i << " ";
    return 0;
}