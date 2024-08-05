#include <iostream>
using namespace std;

int *parent, *arr, *rank, n;

void initialize()
{
    for (int i = 0; i < n; i++)
        parent[i] = i, rank[i] = 0;
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
    {
        if (rank[xset] < rank[yset])
            parent[xset] = yset;
        else if (rank[xset] > rank[yset])
            parent[yset] = xset;
        else
            parent[yset] = xset, rank[xset]++;
    }
}

int main()
{
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    rank = new int[n];
    parent = new int[n];
}