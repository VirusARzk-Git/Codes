#define ll long long

class Solution
{
    vector<int> v, robot;
    ll f(int n, int m, vector<vector<ll>> &memo)
    {
        if (m == 0)
            return 0;
        if (n == 0)
            return 1e18;
        if (memo[n][m] != -1)
            return memo[n][m];
        ll ans = 1e18;
        ll pick = f(n - 1, m - 1, memo) + abs(v[n - 1] - robot[m - 1]);
        ll notPick = f(n - 1, m, memo);
        return memo[n][m] = min(pick, notPick);
    }

public:
    ll minimumTotalDistance(vector<int> &robot_, vector<vector<int>> &factory)
    {
        robot = robot_;
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        for (int i = 0; i < factory.size(); i++)
        {
            int x = factory[i][0], y = factory[i][1];
            while (y--)
                v.push_back(x);
        }
        int N = v.size(), M = robot.size();

        // vector<vector<ll>> memo(N + 1, vector<ll>(M + 1, -1));
        // return f(N, M, memo);

        vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 1e18));
        for (int n = 0; n <= N; n++)
            dp[n][0] = 0;
        for (int m = 1; m <= M; m++)
            for (int n = 1; n <= N; n++)
            {
                ll pick = dp[n - 1][m - 1] + abs(v[n - 1] - robot[m - 1]);
                ll notPick = dp[n - 1][m];
                dp[n][m] = min(pick, notPick);
            }
        return dp[N][M];
    }
};