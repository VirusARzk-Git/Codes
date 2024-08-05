#include <iostream>
using namespace std;
#define ll long long
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        bool flag = true;
        ll k, sum = 0;
        cin >> n >> k;
        ll arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];
            if (sum < k)
            {
                cout << "NO " << i + 1;
                flag = false;
                break;
            }
            sum -= k;
        }
        if (flag)
            cout << "YES";
        cout << endl;
    }

    return 0;
}