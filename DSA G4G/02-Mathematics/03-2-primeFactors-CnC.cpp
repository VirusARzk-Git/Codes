#include <iostream>
#include <vector>
using namespace std;
#define int long long unsigned int
vector<pair<int, int>> v;

void primeFact(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
                n /= i, cnt++;
            v.push_back({i, cnt});
        }
    }
    if (n > 1)
        v.push_back({n, 1});
    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << "^" << v[i].second << endl;
}

signed main()
{
    int n;
    cin >> n;
    primeFact(n);
}