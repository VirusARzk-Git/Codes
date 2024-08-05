#include <iostream>
#include <vector>
using namespace std;

struct stack
{
    vector<int> v;
    void push(int x)
    {
        v.push_back(x);
    }

    int pop()
    {
        int res = v.back();
        v.pop_back();
        return res;
    }

    int size()
    {
        return v.size();
    }

    bool isEmpty()
    {
        return v.empty();
    }

    int peek()
    {
        return v.back();
    }
};

int main()
{
    stack s;
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