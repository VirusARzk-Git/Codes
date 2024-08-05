#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

int getHash(string key)
{
    int value = 0;
    int p = 31;
    int p_power = 1;

    for (char ch : key)
    {
        value = (value + (ch - 'a' + 1) * p_power) % mod;
        p_power = (p_power * p) % mod;
    }
    return value;
}

signed main()
{
    bool flag = 1;
    while (flag)
    {
        string key;
        cout << "\nEnter key\n";
        cin >> key;
        if (key == ".")
            flag = false;
        else
            cout << "Key: " << key << " Hash: " << getHash(key) << endl;
    }
    return 0;
}