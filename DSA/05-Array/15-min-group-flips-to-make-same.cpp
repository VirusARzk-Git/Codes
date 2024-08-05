#include <iostream>
#include <vector>
using namespace std;

void printGroups(string s, int n)
{
    for (int i = 1; i < n; i++)
        if (s[i] != s[i - 1])
            if (s[i] != s[0])
                cout << "from " << i << " to ";
            else
                cout << i - 1 << endl;
    if (s[n - 1] != s[0])
        cout << n - 1 << endl;
}

void func(string s, int n)
{
    int c[2] = {0};
    vector<vector<int>> v(2);
    c[s[0] - '0']++;
    v[s[0] - '0'].push_back(0);
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
            c[s[i] - '0']++, v[s[i] - '0'].push_back(i), v[s[i - 1] - '0'].push_back(i - 1);
    }
    v[s[n - 1] - '0'].push_back(n - 1);
    cout << min(c[0], c[1]) << endl;
    if (v[1].size() < v[2].size())
    {
        for (int i = 0; i < v[0].size(); i += 2)
            cout << v[0][i] << ' ' << v[0][i + 1] << endl;
    }
    else
        for (int i = 0; i < v[1].size(); i += 2)
            cout << v[1][i] << ' ' << v[1][i + 1] << endl;
}

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    printGroups(s, n);
    func(s, n);
}