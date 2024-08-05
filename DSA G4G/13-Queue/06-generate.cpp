// Generate numbers with given digits

#include <iostream>
#include <queue>
#include <set>
#include <string>
using namespace std;

queue<string> printFirstN(int n, set<int> &digits)
{
    queue<string> q;
    queue<string> ans;

    for (auto i : digits)
        q.push(to_string(i));

    for (int i = 0; i < n; i++)
    {
        string curr = q.front();
        ans.push(curr);
        q.pop();
        for (auto i : digits)
        {
            cout << "set " << i << endl;
            q.push(curr + to_string(i));
        }
    }
    return ans;
}

int main()
{
    set<int> s;
    s.insert(5);
    s.insert(6);
    queue<string> q = printFirstN(15, s);
    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
}