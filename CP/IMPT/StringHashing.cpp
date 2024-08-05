class Solution
{
    const int p = 31;
    const int m = 1e9 + 7;

public:
    vector<int> search(string pat, string txt)
    {
        int n = txt.size(), m = pat.size();
        vector<int> ans;
        vector<long long> ppow(m, 1);
        for (int i = 1; i < m; i++)
            ppow[i] = (ppow[i - 1] * p) % m;
        long long h_pat = 0, h_txt = 0;
        for (int i = 0; i < m; i++)
        {
            h_pat = (h_pat * p + pat[i]) % m;
            h_txt = (h_txt * p + txt[i]) % m;
        }
        for (int i = m; i <= n; i++)
        {
            if (h_pat == h_txt)
            {
                bool flag = true;
                for (int j = 0; j < m; j++)
                {
                    if (pat[j] != txt[i - m + j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    ans.push_back(i - m);
            }
            if (i == n)
                break;
            h_txt = (h_txt - (ppow[m - 1] * txt[i - m]) % m + m) % m;
            h_txt = (h_txt * p + txt[i]) % m;
        }
        return ans;
    }
};