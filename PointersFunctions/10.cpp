#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int *p = &a;
    int **q = &p;

    *p = *p + 5;
    p = p;
    **q = **q + 5;

    cout << a;
    return 0;
}