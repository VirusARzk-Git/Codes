// हर हर महादेव
using namespace std;

#include <bits/stdc++.h>
int cnt(int n, int *qb)
{
    if (qb[n] != 0)
        return qb[n];
    return qb[n] = cnt(n - 1, qb) + cnt(n / 2, qb) + cnt(n / 3, qb);
}
int main()
{
    int n;
    cin >> n;
    int qb[n + 1] = {1};
    cout << cnt(n, qb) << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int cnt(int n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }
//     return cnt(n - 1) + cnt(n / 2) + cnt(n / 3);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     cout << cnt(n) << endl;
//     return 0;
// }