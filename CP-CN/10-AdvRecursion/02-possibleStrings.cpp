#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, string> m;

void possibleStrings(string n, vector<string> &ans, int i = 0, string t = "")
{
    if (i == n.size())
    {
        ans.push_back(t);
        return;
    }
    for (auto j : m[n[i]])
        possibleStrings(n, ans, i + 1, t + j);
}

int main()
{
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    string n;
    cin >> n;
    vector<string> ans;
    possibleStrings(n, ans);
    for (auto i : ans)
        cout << i << endl;
}