#include <iostream>
using namespace std;

int main()
{
    int a = 100;
    int *p = &a;
    int *x = p;
    *x -= 5;
    cout << a;
}