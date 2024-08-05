#include <iostream>
#include <unordered_set>
using namespace std;

int intersection(int *a, int n, int *b, int m)
{
    unordered_set<int> s(a, a + n);
    int res = 0;
    for (int i = 0; i < m; i++)
        if (s.find(b[i]) != s.end())
            res++, s.erase(b[i]);
    return res;
}

int main()
{
    int m, n;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    cout << intersection(a, n, b, m);
}