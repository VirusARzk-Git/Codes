#include<iostream>
using namespace std;
int josephus(int n, int k)
{
    if (n == 1)
        return 0;
    return (k + josephus(n - 1, k)) % n;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << josephus(n, k) << endl;
}