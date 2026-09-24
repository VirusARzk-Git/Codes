#include <iostream>
using namespace std;
int main()
{
    int a = 1, b = 3;
    int *p = &a;
    p = &b;
    *p = 7;
    cout << a << b;
    return 0;
}