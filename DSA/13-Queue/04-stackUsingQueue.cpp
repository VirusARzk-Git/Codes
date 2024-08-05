#include <iostream>
#include <queue>
using namespace std;

class stack // push operation costly
{
    queue<int> q1, q2;

public:
    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    int size() { return q1.size(); }

    void pop()
    {
        if (q1.empty())
            return;
        q1.pop();
    }

    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
};

class Stack // pop operation costly
{
    queue<int> q1, q2;

public:
    void pop()
    {
        if (q1.empty())
            return;
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void push(int x) { q1.push(x); }

    int top()
    {
        if (q1.empty())
            return -1;

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int temp = q1.front();
        q1.pop();
        q2.push(temp);

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return temp;
    }

    int size() { return q1.size(); }
};

class Stackk // Using only one queue
{
    queue<int> q;

public:
    void push(int data)
    {
        int s = q.size();
        q.push(data);

        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (!q.empty())
            q.pop();
    }

    int top() { return (q.empty()) ? -1 : q.front(); }

    bool empty() { return (q.empty()); }

    int size() { return q.size(); } 
};

int main()
{
    Stack s;
    s.push(3);
    cout << s.top() << endl;
    s.push(1);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
}
