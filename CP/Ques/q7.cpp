// what does this code do?

#include <iostream>
using namespace std;

int result(int a, int b)
{
    int ans = 0;
    while (b--)
        ans += a;
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << result(a, b);
    return 0;
}