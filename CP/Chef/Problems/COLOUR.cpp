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
#define input_arr               \
    ll arr[n];                  \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define out_arr                 \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

int main()
{
    fast_tc
    {
        int x, y, z;
        cin >> x >> y >> z;
        // if (x + y + z == 0 || x + y + z == 1)
        //     cout << x + y + z << endl;
        // else if (x >= 3 && y >= 3 && z >= 3)
        //     cout << 6 << endl;
        // else if (x + y + z == 2)
        // {
        //     if (x == 2 || y == 2 || z == 2)
        //         cout << 1 << endl;
        //     else
        //         cout << 2 << endl;
        // }
        // else if (x + y + z == 3)
        // {
        //     if (x == 3 || y == 3 || z == 3)
        //         cout << 1 << endl;
        //     else if (x == 2 || y == 2 || z == 2)
        //         cout << 2 << endl;
        //     else
        //         cout << 3 << endl;
        // }
        // else
        // {
        // }

        int arr[4] = {0};
        if (x == 0 || x == 1 || x == 2)
            arr[x]++;
        else
            arr[3]++;
        if (y == 0 || y == 1 || y == 2)
            arr[y]++;
        else
            arr[3]++;
        if (z == 0 || z == 1 || z == 2)
            arr[z]++;
        else
            arr[3]++;

        if (arr[0] == 3)
            cout << 0;
        else if (arr[1] == 3)
            cout << 3;
        else if (arr[2] == 3)
            cout << 4;
        else if (arr[3] == 3)
            cout << 6;
        else if (arr[0] == 2)
            cout << 1;
        else if (arr[0] == 1 && arr[1] >= 1)
            cout << 2;
        else if (arr[0] == 1 && arr[2] + arr[3] == 2)
            cout << 3;
        else if (arr[1] == 2 && arr[0] == 0)
            cout << 3;
        else if (arr[1] == 1 && arr[2] + arr[3] == 2)
            cout << 4;
        else if (arr[2] == 2 && arr[3] == 1)
            cout << 5;
        else if (arr[2] == 1 && arr[3] == 2)
            cout << 5;
        cout << endl;

        // cout << arr[0] << arr[1] << arr[2] << arr[3] << endl;
    }
    return 0;
}