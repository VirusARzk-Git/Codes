
#include <bits/stdc++.h>
using namespace std;

#define int long long
int n = 1000001;
int arr[1000001];
vector<pair<int, int>> pf;

void sieve()
{
    for (int i = 2; i * i < n; i++)
        if (arr[i] == 0)
            for (int j = i * i; j < n; j += i)
                if (arr[j] == 0)
                    arr[j] = i;
}

void factorization(int n)
{
    int k = arr[n], cnt = 0;
    while (n > 1)
    {
        cnt++;
        if (arr[n])
            n /= arr[n];
        else
            n /= n;
        if (arr[n] != k and n != k)
        {
            pf.push_back({k, cnt});
            cnt = 0;
            if (arr[n])
                k = arr[n];
            else
                k = n;
        }
    }
    for (int i = 0; i < pf.size(); i++)
        cout << pf[i].first << '^' << pf[i].second << endl;
}

signed main()
{
    sieve();
    int m;
    cin >> m;
    factorization(m);
    return 0;
}