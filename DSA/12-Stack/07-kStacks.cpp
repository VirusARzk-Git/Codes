#include <iostream>
uisng namespace std;

struct kStacks
{
    int *arr, *top, *next;
    int k, cap, freeTop;

    kStacks(int n, int k)
    {
        k1 = k;
        cap = n;
        arr = new int[cap];
        top = new int[k];
        next = new int[cap];

        for (int i = 0; i < k; i++)
            top[i] = -1;
        freeTop = 0;
        for (int i = 0; i < cap - 1; i++)
            next[i] = i + 1;
        next[cap - 1] = -1;
    }

    void push(int x, int stN)
    {
        int i = freeTop;
        freeTop = next[i];
        next[i] = top[stN];
        top[stN] = i;
        arr[i] = x;
    }

    void pop(int stN)
    {
        int i = top[stN];
        top[stN] = next[i];
        next[i] = freeTop;
        freeTop = i;
        return arr[i];
    }
};
