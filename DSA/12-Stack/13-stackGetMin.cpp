#include <iostream>
#include <stack>
using namespace std;

class stackk
{
    stack<int> mainStack;
    stack<int> auxStack;

public:
    void push(int x)
    {
        mainStack.push(x);
        if (auxStack.empty() || mainStack.top() <= auxStack.top())
            auxStack.push(x);
    }

    void pop()
    {
        if (mainStack.empty())
            return;
        if (mainStack.top() == auxStack.top())
            auxStack.pop();
        mainStack.pop();
    }
};
