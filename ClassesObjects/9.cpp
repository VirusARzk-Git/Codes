#include <iostream>
using namespace std;

class A
{
public:
    A() {
        cout << "C ";
        A obj;
    }
    ~A() { cout << "D "; }
};
int main()  {
    A a1;
}