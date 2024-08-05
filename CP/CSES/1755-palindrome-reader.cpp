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
    string s;
    cin >> s;
    int l = s.length(), c = 0, j = -1;
    int count[26] = {0};
    for (int i = 0; i < l; i++)
        count[s[i] - 'A']++;
    for (int i = 0; i < 26; i++)
        if (count[i] % 2 == 1)
        {
            c++;
            j = i;
        }
    if (c > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    if (j == -1)
    {
        for (int m = 0; m < 26; m++)
        {
            for (int n = 0; n < (count[m]) / 2; n++)
                cout << char('A' + m);
        }
        for (int m = 25; m >= 0; m--)
        {
            for (int n = 0; n < (count[m]) / 2; n++)
                cout << char('A' + m);
        }
    }
    else
    {
        for (int m = 0; m < 26; m++)
        {
            if (m != j)
                for (int n = 0; n < (count[m]) / 2; n++)
                    cout << char('A' + m);
        }

        for (int n = 0; n < (count[j]); n++)
            cout << char('A' + j);

        for (int m = 25; m >= 0; m--)
        {
            for (int n = 0; n < (count[m]) / 2; n++)
            {
                if (m != j)
                    cout << char('A' + m);
            }
        }
    }
    return 0;
}