class Solution
{
    vector<long> dp;
    int delay, forget;
    long f(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int cnt = 1;
        for (int i = delay; i < forget; i++)
            if (n - i >= 0)
                (cnt += f(n - i)) %= 1000000007;
        return dp[n] = cnt;
    }

public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        dp.resize(n + 1, -1);
        this->delay = delay;
        this->forget = forget;
        return (f(n) - f(n - forget) + 1000000007) % 1000000007;
    }
};