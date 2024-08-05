#include <bits/stdc++.h>
#define fast_tc \
    int t;      \
    cin >> t;   \
    while (t--)
#define input_arr               \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define out_arr                 \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '
using namespace std;

int main()
{
    // system("cls");
    fast_tc
    {
        long long n, k;
        cin >> n >> k;
        long long check = k * (k + 1);
        check /= 2;
        if(n>=check)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    return 0;
}