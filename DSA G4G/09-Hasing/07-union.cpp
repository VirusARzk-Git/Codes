#include <iostream>
#include <unordered_set>
using namespace std;

int Union(int *a, int n, int *b, int m)
{
    unordered_set<int> s(a, a + n);
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    return s.size();
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
    cout << Union(a, n, b, m);
}