/*
Aditya Raj
*/
// #include <string>
#include <bits/stdc++.h>
using namespace std;

#define badka_wala_positive_number unsigned long long int
#define badka_wala_number long long int
#define chotka_wala_number int
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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    testcase_chalao_bhai
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int c = 0, f1 = -1, f2 = -1;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
            {
                if (c == 0)
                    f1 = i;
                else if (c == 1)
                    f2 = i;
                c++;
            }
        if (c == 1)
            cout << n << endl;
        else
            cout << f2-f1 << endl;
    }
    return 0;
}