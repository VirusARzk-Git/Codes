#include<iostream>
using namespace std;

void fun(int *p) {
    int b = 20;    p = &b;
}

int main() {
    int a = 10; int *p = &a;
    fun(p);    cout << *p;
}