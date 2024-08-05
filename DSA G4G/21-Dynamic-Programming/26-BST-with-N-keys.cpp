#include <iostream>
using namespace std;

int countBST(int n)
{
    if (n <= 1)
        return 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += countBST(i - 1) * countBST(n - i);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << countBST(n);
}