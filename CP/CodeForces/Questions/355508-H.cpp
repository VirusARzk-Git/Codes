#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    if (len % 2 == 1)
        cout << -1;
    else
    {
        int max1, max2, arr[4] = {0};
        for (int i = 0; i < len; i++)
            if (s[i] == 'L')
                arr[0]++;
            else if (s[i] == 'R')
                arr[1]++;
            else if (s[i] == 'U')
                arr[2]++;
            else if (s[i] == 'D')
                arr[3]++;
        if (arr[0] >= arr[1])
            max1 = arr[0] - arr[1];
        else
            max1 = arr[1] - arr[0];
        if (arr[2] >= arr[3])
            max2 = arr[2] - arr[3];
        else
            max2 = arr[3] - arr[2];
        cout << (max1 + max2) / 2;
    }
    return 0;
}