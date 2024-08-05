// Given a rod of n
// Pieces size can be a or b or c
// Find max number of pieces

#include <iostream>
#include <algorithm>
using namespace std;

int maxPieces(int n, int a, int b, int c)
{
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;
    int res = max({
        maxPieces(n - a, a, b, c),
        maxPieces(n - b, a, b, c),
        maxPieces(n - c, a, b, c),
    });
    if (res == -1)
        return res;
    else
        return res + 1;
}

int main()
{
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    cout << maxPieces(n, a, b, c);
}