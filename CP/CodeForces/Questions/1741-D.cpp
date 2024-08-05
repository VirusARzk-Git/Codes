/*
Aditya Raj
*/
#include <bits/stdc++.h>
// #include <string>
// #include <conio.h>
// #include <stdio.h>
using namespace std;

#define big_Num long long int
#define testcase_chalao_bhai \
    int virus_arzk;          \
    cin >> virus_arzk;       \
    while (virus_arzk--)
big_Num arr[262144];
#define array_input_lelo_bhai   \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define array_print_kardo_bhai  \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << ' '
big_Num final_ans;

void recur(int l, int r)
{
    if (l + 1 == r)
    {
        if (arr[l] > arr[r])
        {
            big_Num temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
        final_ans++;
        }
        return;
    }

    big_Num mid = (l + r) / 2;
    recur(l, mid);
    recur(mid + 1, r);
    if (arr[l] > arr[mid + 1])
    {
        for (int i = l; i <= mid; i++)
        {
            big_Num temp = arr[i];
            arr[i] = arr[mid + i - l + 1];
            arr[mid + i - l + 1] = temp;
        }
        final_ans++;
    }
}

int main()
{
    testcase_chalao_bhai
    {
        final_ans = 0;
        big_Num n;
        cin >> n;
        array_input_lelo_bhai;
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        recur(0, n - 1);
        int flag = 0;
        for (int i = 0; i < n; i++)
            if (arr[i] != i + 1)
            {
                flag = 1;
                break;
            }
        if (flag)
            final_ans = -1;
        cout << final_ans << endl;
    }
    return 0;
}