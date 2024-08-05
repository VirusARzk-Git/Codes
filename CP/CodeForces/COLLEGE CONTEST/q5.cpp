/*
Aditya Raj
*/
// #include <string>
#include <bits/stdc++.h>
using namespace std;

#define llnum unsigned long long int
#define fast_virus     \
    int virus_arzk;    \
    cin >> virus_arzk; \
    while (virus_arzk--)
#define input_array             \
    llnum arr[n];                 \
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
        int n, count = 0;
        cin >> n;
        input_array;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i - 1] < i)
                for (int j = i + 1; j <= n; j++)
                {
                    if (arr[j - 1] < j && arr[j - 1] > i)
                        count++;
                }
        }
        cout << count << endl;
    }
    return 0;
}