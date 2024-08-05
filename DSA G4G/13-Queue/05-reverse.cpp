#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

void reverseRec(queue<int> &q)
{
    if (q.empty())
        return;
    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(12);
    q.push(64);
    cout << q.front() << endl;
    cout << q.back() << endl;
    reverseRec(q);
    cout << q.front() << endl;
    cout << q.back() << endl;
}