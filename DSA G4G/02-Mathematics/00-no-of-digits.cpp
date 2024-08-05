#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int number_of_digits(int a)
{
    return log10(a) + 1;
}

#define infinite_loop while (true)
int main()
{
    infinite_loop
    {
        int a;
        cin >> a;
        cout << number_of_digits(a) << endl;
    }
}