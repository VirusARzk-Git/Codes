#include<iostream>
using namespace std;

void fun(int *p)    {
    p = p + 1;
}

int main()  {
    int a = 10;
    int *p = &a;
    fun(p);
    cout << *p;
}