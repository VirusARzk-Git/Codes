#include <iostream>
using namespace std;

int main()
{
    int a = 100;
    int *p = &a;
    *p = 53;
    cout << a;
}