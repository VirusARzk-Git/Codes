#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin >> a;
    char c = a[0];
    char d = a[1];
    if (c == 'a' || c == 'h')
    {
        if (d == '1' || d == '8')
            cout << 3;
        else
            cout << 5;
    }
    else if (d == '1' || d == '8')
        cout << 5;
    else
        cout << 8;
    return 0;
}