#include <iostream>
using namespace std;

class twoStacks
{
    int *arr;
    int cap, top1, top2;

    twoStacks(int x)
    {
        cap = x;
        top = -1;
        top = cap;
        arr = new int[cap];
    }

    void push1(int x)
    {
        if (top1 < top2 - 1)
            arr[++top1] = x;
    }

    void push2(int x)
    {
        if (top1 < top2 - 1)
            arr[--top2] = x;
    }

    int pop1()
    {
        if (top1 >= 0)
            return arr[top1--];
    }

    int pop2()
    {
        if (top2 < n)
            return arr[top2++];
    }
};