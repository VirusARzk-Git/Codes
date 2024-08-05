#include <bits/stdc++.h>
#define fast_tc \
    int t;      \
    cin >> t;   \
    while (t--)
#define input_a                 \
    int a[n];                   \
    for (int i = 0; i < n; i++) \
    cin >> a[i]

#define input_b                 \
    int hash[n] = {0};          \
    int temp;                   \
    for (int i = 0; i < m; i++) \
    {                           \
        cin >> temp;            \
        hash[temp - 1]++;       \
    }
#define out_arr                  \
    for (int i = 0; i < n; i++)  \
    {                            \
        if (hash[a[i] - 1] == 0) \
            cout << a[i] << ' '; \
    }                            \
    cout << endl;
using namespace std;

int main()
{
    fast_tc
    {
        int n;
        cin >> n;
        input_a;
        int m;
        cin >> m;
        input_b
            out_arr
    }
    return 0;
}