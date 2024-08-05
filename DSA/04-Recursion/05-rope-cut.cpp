/*
a rope of length n has to be cut into pieces of length of either a,b or c,
find the max number of pieces possible
*/


#include <iostream>
using namespace std;
int maxPieces(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    int res = max(max(maxPieces(n - a, a, b, c), maxPieces(n - b, a, b, c)), maxPieces(n - c, a, b, c));
    if (res == -1)
        return -1;
    return res + 1;
}

int main()
{
    while (true)
    {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        cout << maxPieces(n, a, b, c) << endl;
    }
}