// हर हर महादेव
/*
Aditya Raj
*/
#include <bits/stdc++.h>
// #include <string>
// #include <conio.h>
// #include <stdio.h>
using namespace std;

#define B begin()
#define E end()
#define I iterator
using pii = pair<int, int>;
using vi = vector<int>;
#define int long long
#define noTLE ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
#define array_input_lelo_bhai   \
    int arr[n];                 \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define array_print_kardo_bhai  \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

int code_iske_andar_hai()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x = min(a, min(b, c));
    int z = max(a, max(b, c));
    if (z == x)
        return 0;
    int y = a + b + c - z - x;
    if ((z + y) % 2)
        return -1;
    int cnt = (z - y) / 2;
    z += y;
    z /= 2;
    x += cnt;
    z -= x;
    if (z % 2)
        return -1;
    else
        return cnt + z;
}

signed main()
{
    noTLE;
    testcase_chalao_bhai
    {
        cout << code_iske_andar_hai() << endl;
    }
    return 0;
}