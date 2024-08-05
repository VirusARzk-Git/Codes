#include <iostream>
using namespace std;

bool is_Prime(int n)
{
    if (n == 1)
        return false;
    if (n < 4)
        return true;
    if (!(n % 2 && n % 3))
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (!(n % i && n % (i + 2)))
            return false;
    return true;
}

#define infinite_loop while (true)
int main()
{
    infinite_loop
    {
        int n;
        cin >> n;
        if (is_Prime(n))
            cout << "Prime" << endl;
        else
            cout << "Not Prime" << endl;
    }
}