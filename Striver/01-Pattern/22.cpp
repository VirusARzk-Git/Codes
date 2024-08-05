#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < 2 * n; i++)
    {
        for (int j = 1; j < 2 * n; j++)
            cout << n + 1 - min(min(i, n * 2 - i), min(j, n * 2 - j));
        cout << endl;
    }
}