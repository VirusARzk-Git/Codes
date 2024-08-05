#include <iostream>
using namespace std;

int main()
{
    string s = "ABCDE";
    int n = s.length();
    for (int i = n-1; i >=0; i--)
    {
        for (int j = 0; j <= i; j++)
            cout << s[j];
        cout << endl;
    }
}