#include <bits/stdc++.h>
using namespace std;

#define int long long
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int code_iske_andar_hai(int x, int y)
{
    if (x == y || y % x == 0)
        return x;
    if (x > y)
        return x + y;
    // if (x < y)
    //     return x / 2 + y / 2;
    return x + (y - x) / 2;
    return x + gcd(x, y) * x - (y % x) / 2;
}

void tc()
{
    int x = rand() * 2;
    int y = rand() * 2;
    int n = code_iske_andar_hai(x, y);
    if (n % x != y % n)
        cout << x << ' ' << y << ' ' << n << endl;
}

void brute(int x, int y)
{
    cout << "GCD = " << gcd(x, y) << endl;
    cout << "y % x = " << y % x << endl;
    int i;
    for (i = 1; i <= 1000000; i++)
        if (i % x == y % i)
            break;
    cout << "n = " << i << endl;
    cout << "n - x = " << i - x << endl;
    cout << endl;
}

signed main()
{
    testcase_chalao_bhai
    {
        int x, y;
        cin >> x >> y;
        brute(x, y);
        // cout << code_iske_andar_hai(x, y) << endl;
    }
    // cout << (2328 % 12668 == 53000 % 2328) << endl;
    // cout << (111488 % 69420 == 42068 % 111488);
    // cout << 9969128 - 111488 << endl;
    // cout << 9857640 / 69420 << endl;
    // cout << 69420 * 142 << endl;
    return 0;
}