#include <iostream>
using namespace std;

int eggDrop(int f, int e)
{
    if (e == 1 || f <= 1)
        return f;
    int min = INT_MAX;
    for (int x = 1; x <= f; x++)
    {
        int res = max(eggDrop(x - 1, e - 1), eggDrop(f - x, e));
        if (res < min)
            min = res;
    }
    return min + 1;
}

int main()
{
    int f, e;
    cin >> f >> e;
    cout << eggDrop(f, e);
}