/*
Aditya Raj
*/
// #include <string>
#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int
#define fast_tc \
    int t;      \
    cin >> t;   \
    while (t--)

#define out_arr                 \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

int main()
{
    fast_tc
    {
        int n, k, count = 0;
        cin >> n >> k;
        int arr[n], g_c_d = 0, temp_gcd = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            g_c_d = gcd(g_c_d, arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            temp_gcd = gcd(temp_gcd, arr[i]);
            if (temp_gcd == g_c_d)
            {
                count++;
                temp_gcd = 0;
            }
        }
        if (count >= k)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}