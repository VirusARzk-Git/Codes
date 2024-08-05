#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int is_Prime[n] = {0};
    for (int i = 2; i < n; i++)
        is_Prime[i] = 1;
    for (int i = 1; i * i < n; i++)
        if (is_Prime[i] == 1)
            for (int j = i * i; j < n; j += i)
                is_Prime[j] = 0;

    for (int i = 1; i < n; i++)
    {
        if (is_Prime[i])
            cout << i << " is a prime number\n";
    }
}