#include <iostream>
#include <algorithm>
using namespace std;

int edit_Dist(string s1, string s2, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (s1[m - 1] == s2[n - 1])
        return edit_Dist(s1, s2, m - 1, n - 1);
    return 1 + min({edit_Dist(s1, s2, m, n - 1), edit_Dist(s1, s2, m - 1, n - 1), edit_Dist(s1, s2, m - 1, n)});
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << edit_Dist(a, b, a.size(), b.size());
}