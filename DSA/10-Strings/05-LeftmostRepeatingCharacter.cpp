#include <iostream>
using namespace std;

const int CHAR = 256;

int LeftmostRepeatingCharacter(string s)
{
    int fIndex[CHAR];
    fill(fIndex, fIndex + CHAR, -1);
    int res = INT_MAX;
    for (int i = 0; i < s.length(); i++)
    {
        int fi = fIndex[s[i]];
        if (fi == -1)
            fIndex[s[i]] = i;
        else
            res = min(res, fi);
    }
    return (res == INT_MAX) ? -1 : res;
}

int LeftmostRepeatingCharacter2(string s)
{
    bool visited[CHAR];
    fill(visited, visited + CHAR, false);
    int res = -1;
    for (int i = s.length() - 1; i >= 0; i--)
        if (visited[s[i]])
            res = i;
        else
            visited[s[i]] = true;
    return res;
}

#include <unordered_map>
int LeftmostRepeatingCharacter3(string s)
{
    unordered_map<char, bool> visited;
    int res = -1;
    for (int i = s.length() - 1; i >= 0; i--)
        if (visited[s[i]])
            res = i;
        else
            visited[s[i]] = true;
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << LeftmostRepeatingCharacter3(s);
}