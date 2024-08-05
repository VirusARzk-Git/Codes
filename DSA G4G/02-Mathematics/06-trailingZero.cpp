#include <iostream>
using namespace std;

// Count trailing zeros in the factorial of n

int countTrailingZeros(int n)
{
    int result = 0;
    for (int i = 5; i <= n; i *= 5)
        result += n / i;
    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << countTrailingZeros(n);
}