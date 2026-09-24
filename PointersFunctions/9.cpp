#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = 20;
    int *p = &a;
    int **q = &p;
    p = &b;
    **q = 50;

    cout << a << " " << b;
    return 0;
}