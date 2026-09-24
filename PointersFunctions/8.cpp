#include <iostream>
using namespace std;
int main()
{
    int a = 3;
    int *p = &a;
    int **q = &p;

    *p = *p + 2;
    **q = **q + 3;

    cout << a;
    return 0;
}