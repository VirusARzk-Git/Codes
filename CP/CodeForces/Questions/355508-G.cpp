#include <iostream>
using namespace std;
int main()
{
    long long int n, a, b = 0;
    cin >> n;
    cin >> a;
    while (--n)
    {
        cin >> b;
        cout << a + b << ' ';
        a = b;
    }
    cout << a;
    return 0;
}