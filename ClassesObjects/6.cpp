#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "C "; }
    ~A() { cout << "D "; }
};

A fun() {
    A x;
    return x;
}
int main()  {
    A a1 = fun();
}