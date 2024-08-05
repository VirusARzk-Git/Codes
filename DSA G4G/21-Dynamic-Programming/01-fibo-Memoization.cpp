//  Memoization

#include <iostream>
#include <vector>
using namespace std;

vector<int> memo(100000, -1);

int fib(int n)
{
    if (memo[n] == -1)
        if (n < 2)
            return memo[n] = n;
        else
            return memo[n] = fib(n - 1) + fib(n - 2);
    else
        return memo[n];
}

int main()
{
    cout << fib(10);
}