// हर हर महादेव
/*
Aditya Raj
*/
#include <bits/stdc++.h>
// #include <string>
// #include <conio.h>
// #include <stdio.h>
using namespace std;

#define int long long
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
#define array_print_kardo_bhai  \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '

void print(int a, int b)
{
    cout << "? " << b - a + 1 << ' ';
    for (int i = a; i <= b; i++)
        cout << i << ' ';
    cout << endl;
    cout.flush();
}
void code_iske_andar_hai()
{
    int n;
    cin >> n;
    int arr[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    int low = 1, high = n, x, mid;
    mid = (high + low) / 2;
    // print(1, mid);
    while (low < high)
    {
        mid = (high + low) / 2;
        print(low, mid);
        cin >> x;
        int sum = arr[mid] - arr[low - 1];
        if (x > sum)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << "! " << low;
    cout << endl;
}

signed main()
{
    testcase_chalao_bhai
    code_iske_andar_hai();
    return 0;
}