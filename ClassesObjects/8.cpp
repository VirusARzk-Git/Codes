#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "C "; }
    ~A() { cout << "D "; }
}

int main()
{
    A a1;
    {   A a2;   A a3;   }
}