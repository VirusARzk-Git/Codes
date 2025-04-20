#include <iostream>
using namespace std;
int main()
{
    int i = 0, j = 0;
    while (i < 5, j < 10)
    {
        i++;
        j++;
    }
    cout << j + i / 10;
}
