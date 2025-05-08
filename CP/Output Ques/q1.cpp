// Find Output - Pointer

#include <iostream>
using namespace std;

int main()
{
    int a = 5, b = 10;
    int *p1 = &a, *p2 = &b;
    int **pp = &p1;

    cout << **pp << " " << *p2 << endl;
    return 0;
}