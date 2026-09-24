#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "C "; }
    ~A() { cout << "D "; }
};

void fun() { static A x; }

int main()
{
    fun();
    fun();
}