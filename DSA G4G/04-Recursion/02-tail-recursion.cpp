#include <iostream>
using namespace std;

void print_n_to_1(int n)
{
    if (!n)
        return;
    cout << n << " ";
    print_n_to_1(n - 1); // Tail Recursion
}

void tail_print_1_to_n(int n, int k = 1)
{
    if (!n)
        return;
    cout << k << " ";
    tail_print_1_to_n(n - 1, k + 1); // Tail Recursion
}

void print_1_to_n(int n)
{
    if (!n)
        return;
    print_1_to_n(n - 1); // Head Recursion
    cout << n << " ";
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int tail_factorial(int n, int k = 1)
{
    if (n == 0)
        return k;
    return tail_factorial(n - 1, k * n);
}

int main()
{
    int n;
    cin >> n;
    // tail_print_1_to_n(n);
    cout << tail_factorial(n) << endl;
}