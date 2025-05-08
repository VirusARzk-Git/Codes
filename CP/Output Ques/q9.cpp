#include <iostream>
#define sq(x) x *x
#define SQ(x) (x) * (x)
using namespace std;
int main()
{
    cout << SQ(2 + 1) - sq(2 + 1);
    return 0;
}
