#include <iostream>
using namespace std;

int *parent, *arr, n;

void initialize()
{
    for (int i = 0; i < n; i++)
        parent[i] = i;
}

int findd(int x)
{
    if (parent[x] == x)
        return x;
    else
        return findd(parent[x]);
}

void unionn(int x, int y)
{
    int xset = findd(x);
    int yset = findd(y);
    if (xset != yset)
        parent[xset] = yset;
}

int main()
{
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    parent = new int[n];
}