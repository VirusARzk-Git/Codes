#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 101;

vector<int> primes;
int P;
vector<vector<int>> adj;
vector<vector<long long>> dp;
bool is_prime[N];

void sieve()
{
    fill(is_prime, is_prime + N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = 2 * i; j < N; j += i)
                is_prime[j] = false;
        }
    }
    P = primes.size();
}

void preprocess(int N)
{
    sieve();
    adj.clear();
    adj.resize(N);
    dp.clear();
    dp.assign(N, vector<long long>(primes.size(), 1));
}

void dfs(int curr, int parent = -1)
{
    for (int next : adj[curr])
    {
        if (next == parent)
            continue;
        dfs(next, curr);

        for (int i = 0; i < P; i++)
        {
            long long t = 0;
            for (int j = 0; j < P; j++)
            {
                if (is_prime[primes[i] + primes[j]])
                    continue;
                t += dp[next][j];
                t %= MOD;
            }
            dp[curr][i] *= t;
            dp[curr][i] %= MOD;
        }
    }
}

int solve(int N, vector<vector<int>> edges)
{
    preprocess(N);

    if (N == 1)
        return primes.size();

    for (vector<int> edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    dfs(0);
    long long ans = 0;

    for (int i = 0; i < P; i++)
    {
        ans += dp[0][i];
        ans %= MOD;
    }
    return ans;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> edges(N - 1, vector<int>(2));
    for (int i = 0; i < N - 1; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--;
        edges[i][1]--;
    }

    cout << solve(N, edges) << endl;
    return 0;
}