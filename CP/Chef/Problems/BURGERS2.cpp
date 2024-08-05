#include <bits/stdc++.h>
using namespace std;

#define llnum unsigned long long int
#define fast_virus     \
    int virus_arzk;    \
    cin >> virus_arzk; \
    while (virus_arzk--)
#define input_array             \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define out_array               \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fast_virus
    {
        llnum x, y, n, r;
        cin >> x >> y >> n >> r;
        if (x * n > r)
        {
            cout << -1 << endl;
            continue;
        }
        else if (x * n == r)
        {
            cout << n << " 0\n";
            continue;
        }
        else if (y * n <= r)
        {
            cout << 0 << " " << n << endl;
            continue;
        }
        llnum a = n - 1, b = 1;
        while (1)
        {
            if (x * a-- + b++ * y > r)
                break;
        }
        cout << a + 2 << ' ' << b - 2 << endl;
    }
    return 0;
}