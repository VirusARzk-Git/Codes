#include <bits/stdc++.h>
using namespace std;

// #define int long long
int virus = 5555;
#define loop while (virus--)

int table[256];
void initialize()
{
    table[0] = 0;
    for (int i = 1; i < 256; i++)
        table[i] = (i & 1) + table[i / 2];
}
int count(int n)
{
    int res = table[n & 0xFF];
    n = n >> 8;
    res = res + table[n & 0xFF];
    n = n >> 8;
    res = res + table[n & 0xFF];
    n = n >> 8;
    res = res + table[n & 0xFF];
    return res;
}

int number_of_bits(int n)
{
    int cnt = 0;
    while (n)
    {
        if (n & 1)
            cnt++;
        n >>= 1;
    }
    return cnt;
}

signed main()
{
    initialize();
    loop
    {
        int n;
        cin >> n;
        cout << count(n);
        // cout << number_of_bits(n);
        cout << endl;
    }
    return 0;
}