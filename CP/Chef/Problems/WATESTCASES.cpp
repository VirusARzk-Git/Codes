#include <bits/stdc++.h>
using namespace std;

int main()
{
    int virus_arzk;
    cin >> virus_arzk;
    while (virus_arzk--)
    {
        int n, min = 100;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
            if (s[i] == '0' && arr[i] < min)
                min = arr[i];
        cout << min << endl;
    }

    return 0;
}