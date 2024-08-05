// #include <iostream>
#include <bits/stdc++.h>
using namespace std;
// #include <conio.h>
// #include <stdio.h>
// #include <string>

#define ll unsigned long long int
// using namespace std;

// int main()
// {
// system("cls");

// getch();
// return 0;
// }


int main()
{
    int kal_aana_kal;
    cin >> kal_aana_kal;
    while (kal_aana_kal--)
    {
        int n, c = 0;
        cin >> n;
        ll a[n], b[n], ar, br;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
        {
            ar = a[i];
            br = b[i];
            for (int j = i + 1; j < n; j++)
                if (a[j] == br && b[j] == ar)
                    c++;
        }
        cout << c << endl;
    }
    return 0;
}
