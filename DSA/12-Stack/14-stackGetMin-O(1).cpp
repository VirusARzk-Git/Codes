#include <iostream>
#include <stack>
using namespace std;

class stackPositives
{
    stack<int> s;
    int min;

public:
    void push(int x)
    {
        if (s.empty())
        {
            min = x;
            s.push(x);
        }
        else if (x <= min)
        {
            s.push(x - min);
            min = x;
        }
        else
            s.push(x);
    }

    int getMin()
    {
        return min;
    }

    int top()
    {
        int t = s.top();
        return t <= 0 ? min : t;
    }

    void pop()
    {
        if (s.empty())
            return;
        if (s.top() <= 0)
            min = min - s.top();
        s.pop();
    }
};

class stackk
{
    stack<int> s;
    int min;

public:
    void push(int x)
    {
        if (s.empty())
        {
            min = x;
            s.push(x);
        }
        else if (x <= min)
        {
            s.push(2 * x - min);
            min = x;
        }
        else
            s.push(x);
    }

    int getMin()
    {
        return min;
    }

    int top()
    {
        int t = s.top();
        return t <= min ? min : t;
    }

    void pop()
    {
        if (s.empty())
            return;
        if (s.top() <= min)
            min = 2 * min - s.top();
        s.pop();
    }
};