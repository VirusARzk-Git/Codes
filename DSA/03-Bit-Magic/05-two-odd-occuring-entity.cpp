#include <iostream>
using namespace std;

void code(int *arr, int n)
{
    int xorr = 0;
    for (int i = 0; i < n; i++)
        xorr ^= arr[i];
    xorr = xorr & ~(xorr - 1);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & xorr)
            a ^= arr[i];
        else
            b ^= arr[i];
    }
    cout << a << " " << b << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        code(arr, n);
    }
}