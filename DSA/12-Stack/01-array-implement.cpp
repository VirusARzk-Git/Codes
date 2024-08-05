#include <iostream>
using namespace std;

class stack
{
    int *arr;
    int cap;
    int top;

public:
    stack(int sz)
    {
        cap = sz;
        arr = new int[cap];
        top = -1;
    }

    void push(int x)
    {
        top++;
        arr[top] = x;
    }

    int pop()
    {
        int res = arr[top];
        top--;
        return res;
    }

    int peek()
    {
        return arr[top];
    }

    int size()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    stack s(5);
    s.push(1);
    s.push(10);
    s.push(100);
    // cout << s.pop() << endl;
    cout << s.peek() << endl;
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
    cout << s.size() << endl;
}