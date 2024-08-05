#include <iostream>
using namespace std;

bool rotated(string og, string t)
{
    if (og.length() != t.length())
        return false;

    return ((og + og).find(t) != string::npos);
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << rotated(a, b);
}