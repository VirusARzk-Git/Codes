#include <iostream>
using namespace std;

void fun(int x, int &y, int *z) {
    x = x + 10;
    y = y + 20;
    *z = *z + 30;
}
int main() {
    int a = 1, b = 2, c = 3;
    fun(a, b, &c);
    cout << a << " " << b << " " << c;
}