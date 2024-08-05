// #include <conio.h>
// #include <stdio.h>
// #include <string>
#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main()
{
    // system("cls");
    int tatton_ka_saudagar;
    cin >> tatton_ka_saudagar;
    while (tatton_ka_saudagar--)
    {
        int nn, q;
        cin >> nn >> q;
        int arr[nn];
        for (int i = 0; i < nn; i++)
            cin >> arr[i];
        sort(arr, arr + nn);
        while (q--)
        {
            int xo, c = 0;
            cin >> xo;
            for (int i = 0; i < nn; i++)
                if (xo > arr[i])
                {
                    c++;
                    xo = 2 * (xo - arr[i]);
                }
                else
                    break;
            cout << c << endl;
        }
    }
    // getch();
    return 0;
}